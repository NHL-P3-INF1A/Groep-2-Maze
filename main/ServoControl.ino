void motorGripperClose(){
  // Bereken de vertraging (delay) op basis van de hoek (0 graden) van de grijper
  int del = (7 * 0) + 500;
  // Voer 50 pulsen uit om de grijper te sluiten
  for (int pulseCounter = 0; pulseCounter <= 50; pulseCounter++){
      // Activeer de servo motor om de grijper te sluiten
      digitalWrite(MOTOR_SERVO, HIGH);
      // Wacht de berekende vertraging
      delayMicroseconds(del);
      // Deactiveer de servo motor
      digitalWrite(MOTOR_SERVO, LOW);
      // Wacht 20 milliseconden voordat de volgende puls wordt gestuurd
      delay(20);
  }
}

float getDistanceCM() {
  digitalWrite(AFSTAND_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(AFSTAND_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(AFSTAND_TRIGGER, LOW);

  long duration = pulseIn(AFSTAND_ECHO, HIGH);
  float distance = duration * 0.034 / 2;

  // Serial print the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}
void motorGripperOpen(){
  // Bereken de vertraging (delay) op basis van de hoek (180 graden) van de grijper
  int del = (7 * 180) + 500;
  // Voer 50 pulsen uit om de grijper te openen
  for (int pulseCounter = 0; pulseCounter <= 50; pulseCounter++){
      // Activeer de servo motor om de grijper te openen
      digitalWrite(MOTOR_SERVO, HIGH);
      // Wacht de berekende vertraging
      delayMicroseconds(del);
      // Deactiveer de servo motor
      digitalWrite(MOTOR_SERVO, LOW);
      // Wacht 20 milliseconden voordat de volgende puls wordt gestuurd
      delay(20);
  }
}
