void followLine(){
  if(analogRead(IR_SENSORS[0]) > BlackValue || analogRead(IR_SENSORS[1]) > BlackValue){
    motorStop();
    delay(50);
    motorForward(255);
    delay(50);
    //Turn Right
    for(int i = 0; i < 800; i++){
      motorTurnRight(180);
      if(analogRead(IR_SENSORS[5]) < BlackValue){
        break;
      }
      delay(1);
    }
    delay(100);
    for(int i = 0; i < 800; i++){
      motorTurnRight(180);
      if(analogRead(IR_SENSORS[5]) > BlackValue){
        break;
      }
      delay(1);
    }
    motorStop();
  } 
  else if(analogRead(IR_SENSORS[5]) > BlackValue || analogRead(IR_SENSORS[4]) > BlackValue || analogRead(IR_SENSORS[3]) > BlackValue|| analogRead(IR_SENSORS[6]) > BlackValue)
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
     motorTurnRight(100);
     if(analogRead(IR_SENSORS[4]) > BlackValue){
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
       if(analogRead(IR_SENSORS[4]) > BlackValue){
         colorDetected = true;
         break;
       }
       delay(1);
     }
   }
   if(!colorDetected){
    while(colorDetected){
       motorTurnLeft(190);
       if(analogRead(IR_SENSORS[5]) > BlackValue || analogRead(IR_SENSORS[4]) > BlackValue){
         colorDetected = true;
         break;
       }
       delay(1);
     }
   }
   motorStop();
}
