void start() {
  // Start moving forward
  motorForward(170);

  // Wait until all sensors detect black (outline of parking lot)
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}

  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue)) {}

  // Wait until all sensors detect black again
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}
  
  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue)) {}

  // Wait until all sensors detect black againx
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}

  // Wait until only the middle two sensors detect white (vertical black line)
  while (!(analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue)) {}

  // Wait until all sensors detect black again (black box)
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}

  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue)) {}


  // Stop the motors
  motorStop();

  // Close the grippers
  motorGripperClose();

  // Turn left
  motorTurnStartLeft(255);
  delay(700); // Adjust this delay to achieve a 90 degree turn

  // Move a bit forward
  motorForward(255);
  delay(500); // Adjust this delay to move a bit forward

  // Stop the motors before starting to follow the line
  motorStop();

  detectEnd();


  // // Follow the line
  // while (true) {
  //   followLine();
  // }
}
