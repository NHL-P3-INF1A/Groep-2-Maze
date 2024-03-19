void followLine(){
  // Controleer of de sensorwaarde van LineSensor1 of LineSensor2 groter is dan BlackValue
  if(analogRead(IR_SENSORS[0]) > BlackValue || analogRead(IR_SENSORS[1]) > BlackValue){

    
    // Stop de motor
    motorStop();
    // Wacht 50 milliseconden
    delay(50);
    // Rijd vooruit met maximale snelheid
    motorForward(255);
    // Wacht 50 milliseconden
    delay(50);
    // Draai naar rechts
    // Draai 180 graden naar rechts en controleer of de lijn wordt gedetecteerd
    for(int i = 0; i < 800; i++){
      motorTurnRight(180);
      // Als de sensorwaarde van LineSensor6 kleiner is dan BlackValue, stop met draaien
      if(analogRead(IR_SENSORS[5]) < BlackValue){
        break;
      }
      // Wacht 1 milliseconde
      delay(1);
    }
    // Wacht 100 milliseconden
    delay(100);
    // Blijf draaien naar rechts totdat de lijn weer wordt gedetecteerd
    for(int i = 0; i < 800; i++){
      motorTurnRight(180);
      // Als de sensorwaarde van LineSensor6 groter is dan BlackValue, stop met draaien
      if(analogRead(IR_SENSORS[5]) > BlackValue){
        break;
      }
      // Wacht 1 milliseconde
      delay(1);
    }
    // Stop de motor
    motorStop();
  } 
  // Als geen van de sensoren LineSensor1, LineSensor2, LineSensor6, LineSensor5, LineSensor4 of LineSensor7 een zwarte lijn detecteert
  else if(analogRead(IR_SENSORS[5]) > BlackValue || analogRead(IR_SENSORS[4]) > BlackValue || analogRead(IR_SENSORS[3]) > BlackValue|| analogRead(IR_SENSORS[6]) > BlackValue)
  {
    // Rijd vooruit met maximale snelheid
    motorForward(255);
  } 
  // Als geen van de bovenstaande voorwaarden geldt
  else 
  {
    // Roep de functie checkBothSides() aan
    checkBothSides(); 
  }
}

void checkBothSides(){
  // Stop de motor
  motorStop();
   // Wacht 50 milliseconden
   delay(50);
   // Initialiseer een boolean variabele om te controleren of kleur is gedetecteerd
   bool colorDetected = false;
    
   // Controleer rechts
   // Draai 190 graden naar rechts en controleer of de sensorwaarde van LineSensor5 groter is dan BlackValue
   for(int i = 0; i < 400; i++){
     motorTurnRight(190);
     // Als de sensorwaarde van LineSensor5 groter is dan BlackValue, zet colorDetected op true en stop met draaien
     if(analogRead(IR_SENSORS[4]) > BlackValue){
       colorDetected = true;
       break;
     }
     // Wacht 1 milliseconde
     delay(1);
   }
   // Stop de motor
   motorStop();
   // Wacht 100 milliseconden
   delay(100);
    
   // Controleer links als er geen kleur aan de rechterkant wordt gedetecteerd
   if(!colorDetected){
     // Draai 190 graden naar links en controleer of de sensorwaarde van LineSensor5 groter is dan BlackValue
     for(int i = 0; i < 900; i++){
       motorTurnLeft(190);
       // Als de sensorwaarde van LineSensor5 groter is dan BlackValue, zet colorDetected op true en stop met draaien
       if(analogRead(IR_SENSORS[4]) > BlackValue){
         colorDetected = true;
         break;
       }
       // Wacht 1 milliseconde
       delay(1);
     }
   }
   // Als er aan geen van beide zijden kleur wordt gedetecteerd
   if(!colorDetected){
    while(colorDetected){
       // Blijf links draaien totdat kleur wordt gedetecteerd op LineSensor6 of LineSensor5
       motorTurnLeft(190);
       // Als de sensorwaarde van LineSensor6 of LineSensor5 groter is dan BlackValue, zet colorDetected op true en stop met draaien
       if(analogRead(IR_SENSORS[4]) > BlackValue || analogRead(IR_SENSORS[5]) > BlackValue){
         colorDetected = true;
         break;
       }
       // Wacht 1 milliseconde
       delay(1);
     }
   }
   // Stop de motor
   motorStop();
   detectEnd();

}
