
#include <math.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

#include "Wire.h" // This library allows you to communicate with I2C devices.

#define HOST "192.168.0.100"
#define PORT 8080

#define LFT_ACC 0.26
#define UFT_ACC 2.77
#define UFT_GYRO 254.5

#define FALSE 0
#define TRUE 1

#define TEMPORAL_BUFFER_LENGTH 150
#define LFT_TRIGGERED_WATCHTIME 400

#define ALARM_BUZZTIME 40000
#define ALARM_FREQUENCY 1000
#define ALARM_STOP_FREQUENCY 500

#define SAMPLE_RATE 50

#define BUZZ_PIN 13
#define BUTTON_PIN 14

#define WIFI_TRY_FREQUENCY 10000

#define MIN_HELPCALL_INTERVAL 1000

double WIFI_TIMESTAMP;

char ALARM;
double ALARM_TIMESTAMP;
double ALARM_D_TIMESTAMP;

char LFT_TRIGGERED;
double LFT_TRIGGERED_TIMESTAMP;

char WIFI_CONNECTED;
char FALL_DETECTED;
char HELP_ASKED;

const int MPU_ADDR = 0x68; // I2C address of the MPU-6050. If AD0 pin is set to HIGH, the I2C address will be 0x69.

const char* ssid = "Rede Publica"; // SSID
const char* password = "1A2A3A4A"; // Password

int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data

char tmp_str[7]; // temporary variable used in convert function

typedef enum messageType {
  NonSpecific,
  Fall,
  NonReponding,
  Responded,
  HelpCall
} MessageType;

typedef struct mcuData {
  double SAM, SGV;
  double temperature;
} MCUData;

MCUData temporalInfo[TEMPORAL_BUFFER_LENGTH] = {0};
unsigned int lastIndex = 0;

void setup() {
  setupGlobals();

  setupPins();

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  setupMCUBoard();
}

void loop() {
  MCUData currentMCUData;

  configMCURead();

  readMCU();

  /// Calculate Sum Acceleration Magnitude
  currentMCUData.SAM = fabs(convert_accelerometer(accelerometer_x)) +
            + fabs(convert_accelerometer(accelerometer_y))
            + fabs(convert_accelerometer(accelerometer_z));

  /// Calculate Sum Gyroscope Velocity
  currentMCUData.SGV = fabs(convert_gyro(gyro_x)) +
            + fabs(convert_gyro(gyro_y))
            + fabs(convert_gyro(gyro_z));

  if(!checkMCUConnected(currentMCUData)) {
    Serial.println("MCU Board not connected!");
    return;
  }

  currentMCUData.temperature = convert_temperature(temperature);

  temporalInfo[(lastIndex %= TEMPORAL_BUFFER_LENGTH)++] = currentMCUData;

  checkWifi();

  checkFall(currentMCUData);

  checkAlarm();

//  printMCU(currentMCUData);

  delay(1000/SAMPLE_RATE);
}

char* convert_int16_to_str(int16_t i) {
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}

char* convert_double_to_str(double i) {
  sprintf(tmp_str, "%6lf", i);
  return tmp_str;
}

double convert_accelerometer(int16_t value) {
  return value/(8192.0*2);
}

double convert_gyro(int16_t value) {
  return value/(65.5*2);
}

double convert_temperature(int16_t value) {
  return value/340.00+36.53;
}

void setupGlobals() {
  WIFI_CONNECTED = FALSE;
  FALL_DETECTED = FALSE;
  HELP_ASKED = FALSE;

  LFT_TRIGGERED = FALSE;
  LFT_TRIGGERED_TIMESTAMP = 0.0;

  ALARM = FALSE;
  ALARM_TIMESTAMP = 0.0;
  ALARM_D_TIMESTAMP = 0.0;

  WIFI_TIMESTAMP = 0.0;
}

void setupPins() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

char checkWifi() {
  if(WiFi.status() != WL_CONNECTED) {
    WIFI_CONNECTED = FALSE;
    if(millis() - WIFI_TIMESTAMP > WIFI_TRY_FREQUENCY) {
      Serial.println("Connecting to wifi...");
      WiFi.begin(ssid, password);

      WIFI_TIMESTAMP = millis();
    }
  } else {
    if(!WIFI_CONNECTED) {
      WIFI_CONNECTED = TRUE;
      Serial.println("WiFi connection Successful");

      Serial.print("The IP Address of ESP8266 Module is: ");
      Serial.println(WiFi.localIP());
    }
  }

  return (WiFi.status() == WL_CONNECTED);
}

void setupMCUBoard() {
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)

  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)

  Wire.endTransmission(false);
  Wire.write(0x1C); // AFS_SEL register
  Wire.write(0x08);

  Wire.endTransmission(false);
  Wire.write(0x1B); // FS_SEL register
  Wire.write(0x08);

  Wire.endTransmission(false);
  Wire.write(0x75); // WHO_AM_I register
  Wire.write(0x7C);

  Wire.endTransmission(true);
}

void configMCURead() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
}

double readMCU() {
  accelerometer_x = Wire.read() << 8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read() << 8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read() << 8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)

  // Serial.print("[ ");
  // Serial.print(convert_double_to_str(convert_accelerometer(accelerometer_x)));
  // Serial.print(", ");
  // Serial.print(convert_double_to_str(convert_accelerometer(accelerometer_y)));
  // Serial.print(", ");
  // Serial.print(convert_double_to_str(convert_accelerometer(accelerometer_z)));
  // Serial.print("]");

  temperature = Wire.read() << 8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)

  gyro_x = Wire.read() << 8 | Wire.read(); // reading registers: 0x43 (GYRO_XOUT_H) and 0x44 (GYRO_XOUT_L)
  gyro_y = Wire.read() << 8 | Wire.read(); // reading registers: 0x45 (GYRO_YOUT_H) and 0x46 (GYRO_YOUT_L)
  gyro_z = Wire.read() << 8 | Wire.read(); // reading registers: 0x47 (GYRO_ZOUT_H) and 0x48 (GYRO_ZOUT_L)

  // Serial.print("[ ");
  // Serial.print(convert_double_to_str(convert_gyro(gyro_x)));
  // Serial.print(", ");
  // Serial.print(convert_double_to_str(convert_gyro(gyro_y)));
  // Serial.print(", ");
  // Serial.print(convert_double_to_str(convert_gyro(gyro_z)));
  // Serial.print("]");
}

char checkMCUConnected(MCUData mcuData) {
  return mcuData.SAM > 0.05;
}

void printMCU(MCUData mcuData) {
  Serial.print("SAM = "); Serial.print(convert_double_to_str(mcuData.SAM));
  Serial.print(" | SAM = "); Serial.print(convert_double_to_str(mcuData.SGV));
  Serial.print(" | tmp = "); Serial.print(convert_double_to_str(mcuData.temperature));
  Serial.print(" | millis = "); Serial.print(convert_double_to_str(millis()));
  Serial.println();
}


void alertServerFall() {
  int i;
  HTTPClient http;
  String temporalSeries;
  String request;

//  if(WiFi.status() != WL_CONNECTED && !wifiConnect())
//    return;

  http.writeToStream(&Serial);
  http.begin(HOST, PORT, "/FallDetected/");
  http.addHeader("Content-Type", "application/json; charset=utf-8");

  request = "{\r\n"
    "\t\"MAC\":\"60:01:94:25:96:63\",\r\n"
    "\t\"timestamp\":0000000000000000,\r\n"
    "\t\"message_type\":" + String(Fall) + ",\r\n"
    "\t\"message\":\"Fall detected\",\r\n"
    "\t\"temporal_info\":[\r\n";

  for (i = ((lastIndex+1)%TEMPORAL_BUFFER_LENGTH); i != lastIndex; (++i) %= TEMPORAL_BUFFER_LENGTH) {

    temporalSeries += String("\t\t[ ");
    temporalSeries += String(convert_double_to_str(temporalInfo[i].SAM));
    temporalSeries += String(", ");
    temporalSeries += String(convert_double_to_str(temporalInfo[i].SGV));
    temporalSeries += String(", ");
    temporalSeries += String(convert_double_to_str(temporalInfo[i].temperature));
    temporalSeries += String("]");

    if(((i+1) % TEMPORAL_BUFFER_LENGTH) != lastIndex) {
      temporalSeries += String(",");
    }
    temporalSeries += String("\r\n");
  }

  request += temporalSeries;
  request += "\t]\r\n"
      "}";

  Serial.println(request);

  int httpCode = http.POST(request);
  String payload = http.getString();

  Serial.println(httpCode);
  Serial.println(payload);

  http.end();
}

void checkFall(MCUData mcuData) {
  /// if accelerometer`s lower fall got triggered now
  if(mcuData.SAM <= LFT_ACC) {
    /// setup for next steps
    LFT_TRIGGERED = TRUE;
    LFT_TRIGGERED_TIMESTAMP = millis();
    Serial.print("LFT_ACC triggered");
    Serial.println();
  }

  /// if accelerometer`s lower fall threshold was triggered
  if(LFT_TRIGGERED) {
    digitalWrite(LED_BUILTIN, LOW);
    /// if it`s within accelerometer`s upper threshold watch time
    Serial.print(convert_double_to_str(millis() - LFT_TRIGGERED_TIMESTAMP));
    if(millis() - LFT_TRIGGERED_TIMESTAMP < LFT_TRIGGERED_WATCHTIME) {
      Serial.print(" within watchtime ");
      /// if accelerometer`s upper threshold got triggered
      if(mcuData.SAM >= UFT_ACC) {
        Serial.print(" | UFT_ACC triggered");
        /// if gyro upper treshold got triggered
        if(mcuData.SGV >= UFT_GYRO) {
          Serial.print(" | UFT_GYRO triggered");
          FALL_DETECTED = TRUE;
        }
      }
    } else { //< it`s no longer on watch time
      if(FALL_DETECTED) {
        Serial.println();
        Serial.println("FALL DETECTED!");
        alertServerFall();
        turnAlarm();

        FALL_DETECTED = FALSE;
      }

      digitalWrite(LED_BUILTIN, HIGH);
      LFT_TRIGGERED = FALSE;
    }
    Serial.println();
  }
}

void turnAlarm() {
  ALARM = TRUE;
  ALARM_TIMESTAMP = millis();
}

void checkAlarm() {
  int buttonState = digitalRead(BUTTON_PIN);

  // Serial.println(buttonState);

  // if(buttonState && !ALARM) {
  //  alertServerMessage("Help call", 3);
  // }

//  Serial.println(buttonState);
  if(!buttonState) {
    if(ALARM) {
      if(millis() - ALARM_TIMESTAMP < ALARM_BUZZTIME) {
        if(((int)(millis() - ALARM_TIMESTAMP) / ALARM_STOP_FREQUENCY) % 2) {
          noTone(BUZZ_PIN);
        } else {
          tone(BUZZ_PIN, ALARM_FREQUENCY);
        }
      } else {
        /// False alarm button not triggered
        alertServerMessage("Wearer not responding", NonReponding);
        ALARM = FALSE;
      }
    } else {
      if(HELP_ASKED) {
        Serial.println("Wearer help call");
        alertServerMessage("Wearer help call", Responded);

        ALARM_D_TIMESTAMP = millis();
        HELP_ASKED = FALSE;
      }
    }
  } else {
    if(ALARM) {
      Serial.println("Wearer responded");
      alertServerMessage("Wearer responded", Responded);
      ALARM = FALSE;
      noTone(BUZZ_PIN);
      ALARM_D_TIMESTAMP = millis();
    } else {
      if(!HELP_ASKED && (millis() - ALARM_D_TIMESTAMP > MIN_HELPCALL_INTERVAL)) {
        HELP_ASKED = TRUE;
      }
    }
  }
}

void alertServerMessage(String message, MessageType messageType) {
  int i;
  HTTPClient http;
  String request;

//  if(WiFi.status() != WL_CONNECTED && !wifiConnect())
//    return;

  Serial.println("Sending " + message + " request");

  http.writeToStream(&Serial);
  http.begin(HOST, PORT, "/Message/");
  http.addHeader("Content-Type", "application/json; charset=utf-8");

  request = "{\r\n"
    "\t\"MAC\":\"60:01:94:25:96:63\",\r\n"
    "\t\"timestamp\":0000000000000000,\r\n"
    "\t\"message_type\":" + String(messageType) + ",\r\n"
    "\t\"message\":\"" + message + "\"\r\n"
    "}";

  Serial.println(request);

  int httpCode = http.POST(request);
  String payload = http.getString();

  Serial.println(httpCode);
  Serial.println(payload);

  http.end();
}
