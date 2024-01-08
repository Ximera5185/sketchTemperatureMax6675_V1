#include "max6675.h"

int thermoDO = 2;  //он же SO
int thermoCS = 3;
int thermoCLK = 4;  //он же SCK
int ledPin = 13; // переменная с пином подключенного светодиода
int temperature;
int criticalTemperature = 100;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

int vccPin = 5;  //пин для питания
int gndPin = 6;  //пин для земли
String key = "term";
String package;

void setup() {
  Serial.begin(9600);
  //активируем питание и землю
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  pinMode(ledPin,OUTPUT); // назначаем наш пин выходом

  //ждем стабилизации чипа MAX
  delay(500);
}

void loop() {
  //Выводим показания в монитор порта
    //Serial.println((int)thermocouple.readCelsius());
    temperature = (int)thermocouple.readCelsius();
    //package = key + (int)thermocouple.readCelsius();
    package = key + temperature;

    Serial.println(package);

    TurnAlarm();

 delay(1000); // Найти у Гайвера цикл таймера Gyver
}

void TurnAlarm()
{
  if(temperature >= criticalTemperature)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}