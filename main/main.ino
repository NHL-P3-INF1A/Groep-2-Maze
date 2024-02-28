#include <Adafruit_NeoPixel.h>

// NeoPixel setup
#define NEOPIXEL_PIN     4  // Define the pin connected to NeoPixels
#define NUMPIXELS        4  // Number of NeoPixels

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

const int MOTOR_SERVO = 5;

const int motorA1 = 9; 
const int motorA2 = 3;
const int motorB1 = 10;
const int motorB2 = 11;
const int motorB2_afwijking = 2;

const int LineSensor1 = A5;
const int LineSensor2 = A4;
const int LineSensor4 = A3;
const int LineSensor5 = A2;
const int LineSensor6 = A1;
const int LineSensor7 = A0;

const int AFSTAND_ECHO = 8;
const int AFSTAND_TRIGGER = 2;

const int BlackValue = 850;

float duration_us;

bool SERVO_CLOSED = false;

unsigned long timerGripper = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_SERVO, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(AFSTAND_ECHO, INPUT);
  pinMode(AFSTAND_TRIGGER, OUTPUT);

  pixels.begin();
  frontLights();
  

}

void loop() {
  followLine();
}







