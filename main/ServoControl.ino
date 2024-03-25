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
