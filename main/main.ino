#include <Adafruit_NeoPixel.h>

// NeoPixel setup
#define NEOPIXEL_PIN     4  // Pin die verbonden is met de NeoPixels
#define NUMPIXELS        4  // Aantal NeoPixels

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

const int MOTOR_SERVO = 6;

const int motorA1 = 9; 
const int motorA2 = 3;
const int motorB1 = 10;
const int motorB2 = 11;
const int motorB2_afwijking = 2;  // Compensatie voor eventuele afwijking in motor B2

const int IR_SENSORS[] = {A1, A7, A0, A2, A3, A6, A4, A5};

const int AFSTAND_ECHO = 2;
const int AFSTAND_TRIGGER = 7;

const int BlackValue = 850;  // Drempelwaarde voor zwartdetectie door de lijnsensoren

float duration_us;

bool SERVO_CLOSED = false;

unsigned long timerGripper = 0;

void setup() {
  Serial.begin(9600); // Start de serial monitor
  pinMode(MOTOR_SERVO, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  // line sensors???
  pinMode(motorB2, OUTPUT);
  pinMode(AFSTAND_ECHO, INPUT);
  pinMode(AFSTAND_TRIGGER, OUTPUT);

  pixels.begin(); // Start de NeoPixel LED's
  frontLights();  // Zet de voorlichten aan 
}
void loop() {
getDistanceCM();

if(getDistanceCM() < 25){
  start();
} else {
  motorStop();
}
}


void detectEnd() {
  while (true) {
    // Check if all sensors detect black
    if (analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue) {
      // Open the grippers
      motorStop();
      motorForward(160);
      delay(300);
    if (analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue) {

      motorGripperOpen();

      // Move backwards
      motorBackward(255);
      delay(1000); // Adjust this delay to move the desired distance

      // Stop the motors
      motorStop();

      // Break the loop
      break;
      }
    } else {
      // Follow the line
      followLine();
    }
  }
}
