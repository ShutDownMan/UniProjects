
const int esq1 = 12, esq2 = 11;
const int dir1 = 8, dir2 = 7;

void setup() {
  Serial.begin(9600);

  pinMode(esq1, OUTPUT);
  pinMode(esq2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
}

char cmd;

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();

    switch (cmd) {
      case 'w':
        Serial.println("FRENTE");
        digitalWrite(esq1, HIGH);
        digitalWrite(esq2, LOW);
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);
        break;
      case 'p':
        Serial.println("PARAR");
        digitalWrite(esq1, LOW);
        digitalWrite(esq2, LOW);
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, LOW);
        break;
      default:
        Serial.println("jubilei");
        break;
    }
  }
}
