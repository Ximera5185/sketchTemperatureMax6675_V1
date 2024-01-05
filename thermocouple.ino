#include "max6675.h"

int thermoDO = 2;  //он же SO
int thermoCS = 3;
int thermoCLK = 4;  //он же SCK

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

int vccPin = 5;  //пин для питания
int gndPin = 6;  //пин для земли



void setup() {
  Serial.begin(9600);
  //активируем питание и землю
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);

  //ждем стабилизации чипа MAX
  delay(500);
}

void loop() {
  //Выводим показания в монитор порта
    Serial.println((int)thermocouple.readCelsius());
 delay(200);
}
