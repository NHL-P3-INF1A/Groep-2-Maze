void readIrOutput()
{
  for (int sensorPin : IR_SENSORS)
  {
    Serial.print(analogRead(sensorPin));
    Serial.print(" ");
  }
  Serial.print(" 800");
  Serial.println();
}


