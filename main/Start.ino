void Start() {
  // Start the motor moving forward at a speed of 200
  motorForward(255);
  delay(20);
  motorForward(155);

  // Keep checking the sensor conditions in a loop
if (analogRead(IR_SENSORS[3]) > 800 && analogRead(IR_SENSORS[4]) > 800 && analogRead(IR_SENSORS[0]) < 800 && analogRead(IR_SENSORS[1]) < 800 && analogRead(IR_SENSORS[2]) < 800 && analogRead(IR_SENSORS[5]) < 800 && analogRead(IR_SENSORS[6]) < 800) {
        motorStop();
      }

  // After exiting the loop and stopping the motor, call followLine()
  followLine();
}
