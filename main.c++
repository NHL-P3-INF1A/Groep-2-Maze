// NeoPixel setup
#define NEOPIXEL_PIN     4  // Define the pin connected to NeoPixels
#define NUMPIXELS        4  // Number of NeoPixels

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

const int MOTOR_SERVO = 8;

const int motorA1 = 9; 
const int motorA2 = 3;
const int motorB1 = 10;
const int motorB2 = 11;
const int motorB2_afwijking = 13;

const int LineSensor1 = A5;
const int LineSensor2 = A4;
const int LineSensor4 = A3;
const int LineSensor5 = A2;
const int LineSensor6 = A1;
const int LineSensor7 = A0;

const int BlackValue = 900;


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
void turnSignalLeftOn() {
  pixels.setPixelColor(0, pixels.Color(70, 255, 0)); 
  pixels.setPixelColor(3, pixels.Color(70, 255, 0)); 
  pixels.show();
}

void turnSignalLeftOff(){
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); 
  pixels.setPixelColor(3, pixels.Color(0, 0, 0)); 
  pixels.show();
}

void turnSignalRightOn() {
  pixels.setPixelColor(1, pixels.Color(70, 255, 0)); 
  pixels.setPixelColor(2, pixels.Color(70, 255, 0)); 
  pixels.show();
}

void turnSignalRightOff() {
  pixels.setPixelColor(1, pixels.Color(0, 0, 0)); 
  pixels.setPixelColor(2, pixels.Color(0, 0, 0)); 
  pixels.show();
}

void brakeSignalOn() {
  pixels.setPixelColor(0, pixels.Color(0, 255, 0)); 
  pixels.setPixelColor(1, pixels.Color(0, 255, 0)); 
  pixels.show();
}
void brakeSignalOff() {
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); 
  pixels.setPixelColor(1, pixels.Color(0, 0, 0)); 
  pixels.show();
}

void frontLights(){
  pixels.setPixelColor(3, pixels.Color(255, 255, 255)); 
  pixels.setPixelColor(2, pixels.Color(255, 255, 255)); 
  pixels.show();
}
void followLine(){
  if(analogRead(LineSensor1) > BlackValue || analogRead(LineSensor2) > BlackValue){
    motorStop();
    delay(100);
    motorForward(230);
    delay(50);
    //Turn Right
    for(int i = 0; i < 800; i++){
      motorTurnRight(180);
      if(analogRead(LineSensor6) < BlackValue){
        break;
      }
      delay(1);
    }
    delay(100);
    for(int i = 0; i < 800; i++){
      motorTurnRight(180);
      if(analogRead(LineSensor6) > BlackValue){
        break;
      }
      delay(1);
    }
    motorStop();
  } 
  else if(analogRead(LineSensor6) > BlackValue || analogRead(LineSensor5) > BlackValue || analogRead(LineSensor4) > BlackValue|| analogRead(LineSensor7) > BlackValue)
  {
    motorForward(255);
  } 
  else 
  {
    checkBothSides(); 
  }
  
}
void checkBothSides(){
  motorStop();
   delay(200);
   bool colorDetected = false;
    
   //check Right
   for(int i = 0; i < 400; i++){
     motorTurnRight(190);
     if(analogRead(LineSensor5) > BlackValue){
       colorDetected = true;
       break;
     }
     delay(1);
   }
   motorStop();
   delay(200);
    
   //check Left
   if(!colorDetected){
     for(int i = 0; i < 900; i++){
       motorTurnLeft(190);
       if(analogRead(LineSensor5) > BlackValue){
         colorDetected = true;
         break;
       }
       delay(1);
     }
   }
   if(!colorDetected){
    while(colorDetected){
       motorTurnLeft(190);
       if(analogRead(LineSensor6) > BlackValue || analogRead(LineSensor5) > BlackValue){
         colorDetected = true;
         break;
       }
       delay(1);
     }
   }
   motorStop();
}

void motorForward(int motorSpeed){
  analogWrite(motorA1, motorSpeed);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, motorSpeed - motorB2_afwijking);
}

void motorTurnRight(int motorSpeed){
  analogWrite(motorA1, motorSpeed);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, motorSpeed - motorB2_afwijking);
  analogWrite(motorB2, 0);
}

void motorTurnLeft(int motorSpeed){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, motorSpeed);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, motorSpeed - motorB2_afwijking);
}
void motorRight(int motorSpeed){
  analogWrite(motorA1, motorSpeed);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 150 - motorB2_afwijking);

}
void motorLeft(int motorSpeed){
  analogWrite(motorA1, 150);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, motorSpeed - motorB2_afwijking);
 
}
void motorBackward(int motorSpeed){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, motorSpeed);
  analogWrite(motorB1, motorSpeed - motorB2_afwijking);
  analogWrite(motorB2, 0);

}
void motorStop(){
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}