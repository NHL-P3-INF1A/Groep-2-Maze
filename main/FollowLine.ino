void followLine(){
  // Controleer of de sensorwaarde van LineSensor1 of LineSensor2 groter is dan BlackValue
  if(analogRead(IR_SENSORS[0]) > BlackValue || analogRead(IR_SENSORS[1]) > BlackValue){

    
    // Stop de motor
    motorStop();
    // Wacht 50 milliseconden
    // delay(50);
    // // Rijd vooruit met maximale snelheid
    // motorForward(255);
    // // Wacht 50 milliseconden
    // delay(50);
    // // Draai naar rechts
    
    // // Wacht 100 milliseconden
    // delay(100);
    // Blijf draaien naar rechts totdat de lijn weer wordt gedetecteerd
    motorTurnLeft(175);
    delay(250);
    while (true) {
      motorTurnLeft(180);
      // Als de sensorwaarde van LineSensor6 groter is dan BlackValue, stop met draaien
      if(analogRead(IR_SENSORS[6]) > BlackValue){
        break;
      }
      // Wacht 1 milliseconde
      delay(1);
    }
    // Stop de motor
    motorStop();
  } 
  // Als geen van de sensoren LineSensor1, LineSensor2, LineSensor6, LineSensor5, LineSensor4 of LineSensor7 een zwarte lijn detecteert
  else if(analogRead(IR_SENSORS[5]) > BlackValue || analogRead(IR_SENSORS[4]) > BlackValue || analogRead(IR_SENSORS[3]) > BlackValue)
  {
    // Rijd vooruit met maximale snelheid
    motorForward(180);
  } 
  else if (analogRead(IR_SENSORS[7]) > BlackValue || analogRead(IR_SENSORS[6]) > BlackValue)
  {
    motorTurnRight(180);
    delay(150);
    while (true) {
      motorTurnRight(180);
      // Als de sensorwaarde van LineSensor6 groter is dan BlackValue, stop met draaien
      if(analogRead(IR_SENSORS[4]) > BlackValue){
        break;
      }
      // Wacht 1 milliseconde
      delay(1);
    }
  }
  // Als geen van de bovenstaande voorwaarden geldt
  else 
  {
    motorTurnLeft(180);
    motorRightBackwards(180);
    while (true) {
      motorTurnLeft(180);
      // Als de sensorwaarde van LineSensor6 groter is dan BlackValue, stop met draaien
      if(analogRead(IR_SENSORS[6]) > BlackValue){
        break;
      }
      // Wacht 1 milliseconde
      delay(1);
    }
  }


   // Stop de motor
  //  motorStop();
  //  detectEnd();

}
