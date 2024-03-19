void motorForward(int motorSpeed){
  // Activeer motorA om vooruit te bewegen met de opgegeven snelheid
  analogWrite(motorA1, motorSpeed);
  analogWrite(motorA2, 0);
  // Activeer motorB om vooruit te bewegen met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorB1, 0);
  analogWrite(motorB2, motorSpeed - motorB2_afwijking);
}

void motorTurnRight(int motorSpeed){
  // Activeer motorA om vooruit te bewegen met de opgegeven snelheid
  analogWrite(motorA1, motorSpeed);
  analogWrite(motorA2, 0);
  // Activeer motorB om rechtsaf te draaien met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorB1, motorSpeed - motorB2_afwijking);
  analogWrite(motorB2, 0);
}

void motorTurnLeft(int motorSpeed){
  // Activeer motorA om linksaf te draaien met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorA1, 0);
  analogWrite(motorA2, motorSpeed);
  // Activeer motorB om vooruit te bewegen met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorB1, 0);
  analogWrite(motorB2, motorSpeed - motorB2_afwijking);
}

void motorRight(int motorSpeed){
  // Activeer motorA om rechtsaf te draaien met de opgegeven snelheid
  analogWrite(motorA1, motorSpeed);
  analogWrite(motorA2, 0);
  // Activeer motorB om rechtsaf te draaien met een vaste snelheid, met een eventuele afwijking
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 150 - motorB2_afwijking);
}

void motorLeft(int motorSpeed){
  // Activeer motorA om vooruit te bewegen met een vaste snelheid
  analogWrite(motorA1, 150);
  analogWrite(motorA2, 0);
  // Activeer motorB om linksaf te draaien met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorB1, 0);
  analogWrite(motorB2, motorSpeed - motorB2_afwijking);
}

void motorBackward(int motorSpeed){
  // Activeer motorA om achteruit te bewegen met de opgegeven snelheid
  analogWrite(motorA1, 0);
  analogWrite(motorA2, motorSpeed);
  // Activeer motorB om achteruit te bewegen met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorB1, motorSpeed - motorB2_afwijking);
  analogWrite(motorB2, 0);
}

void motorStop(){
  // Stop alle motoren
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

void motorTurnStartLeft(int motorSpeed){
  // Activeer motorA om linksaf te draaien met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorA1, 0);
  analogWrite(motorA2, 0);
  // Activeer motorB om vooruit te bewegen met de opgegeven snelheid, met een eventuele afwijking
  analogWrite(motorB1, 0);
  analogWrite(motorB2, motorSpeed - motorB2_afwijking);
}
