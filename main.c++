const int motorA1 = 6;
const int motorA2 = 9;
const int motorB1 = 10;
const int motorB2 = 11;

const int linePins[] = {A0, A1, A2, A3, A4, A5};

int baselineReadings[6]; 

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    baselineReadings[i] = analogRead(linePins[i]);
  }
}

