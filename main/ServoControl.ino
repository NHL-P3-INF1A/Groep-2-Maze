void motorGripperClose(){
  int del=(7*0)+500;
  for (int pulseCounter=0; pulseCounter<=50; pulseCounter++){
      digitalWrite(MOTOR_SERVO,HIGH);
      delayMicroseconds(del);
      digitalWrite(MOTOR_SERVO,LOW);
      delay(20);
  }
}
void motorGripperOpen(){
  int del=(7*180)+500;
  for (int pulseCounter=0; pulseCounter<=50; pulseCounter++){
      digitalWrite(MOTOR_SERVO,HIGH);
      delayMicroseconds(del);
      digitalWrite(MOTOR_SERVO,LOW);
      delay(20);
  }
}