#include <stdio.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

char c, i;
char tam, str[16];

void loop() {
  tam = i = str[0] = 0;
  while(Serial.available()) {
    str[tam++] = Serial.read();
  }

  str[tam] = 0;
  
  if(!strcmp(str, "liga")) {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }

  for(i = 0; str[i]; ++i) {
    Serial.print(str[i]);    
  }
  Serial.println();

  delay(1000);
}
