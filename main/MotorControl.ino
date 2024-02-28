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