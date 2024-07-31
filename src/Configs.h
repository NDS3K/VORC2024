#include <Adafruit_PWMServoDriver.h>
#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <PS2X_lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>
#include <algorithm>
#include <SPI.h>

//DC
#define pin1_dc1 8 
#define pin2_dc1 9 
#define pin1_dc2 10
#define pin2_dc2 11
#define pin1_dc3 12
#define pin2_dc3 13
#define pin1_dc4 14
#define pin2_dc4 15

//Servo
#define servo_1 7
#define servo_2 6
#define servo_3 3
#define servo_4 2

//Distance Sensor
const int trig = 2;    
const int echo = 39;    

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_401MS, TCS34725_GAIN_1X);

void initialize()
{
    Wire.begin();
    Serial.begin(115200);
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);
    Wire.setClock(400000);
}
void Sensor_ini()
{
    if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
} 
void distance_ini()
{  
    pinMode(trig,OUTPUT);  
    pinMode(echo,INPUT);    
}
 

