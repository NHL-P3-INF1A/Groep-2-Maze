void followLine(){
  if(analogRead(LineSensor1) > BlackValue || analogRead(LineSensor2) > BlackValue){
    motorStop();
    delay(50);
    motorForward(255);
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
   delay(50);
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
   delay(100);
    
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

