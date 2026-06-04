#include <Arduino.h>
#include <Servo.h>
#include "buzzer.hpp"
#include "led.hpp"
#include "notas.hpp"
#include "sensor.hpp"

const byte led1[] = {LED1_R, LED1_G, LED1_B};
Servo servo;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  servo.attach(10);
  servo.write(0);
  
  for(byte pin : led1){
    pinMode(pin, OUTPUT);
  }
  
  Serial.begin(9600); 
  Serial.println("Sistema iniciado"); 
  
  checaProximidadeInicial(led1);

  delay(200);
}


void loop()
{
  checaProximidade(led1, servo);

  delay(100);
}