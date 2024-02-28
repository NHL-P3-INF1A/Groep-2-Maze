void turnSignalLeftOn() {
  // Turn signal on
  pixels.setPixelColor(0, pixels.Color(70, 255, 0)); // Orange color
  pixels.setPixelColor(3, pixels.Color(70, 255, 0)); // Orange color
  pixels.show();
}

void turnSignalLeftOff(){
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Orange color
  pixels.setPixelColor(3, pixels.Color(0, 0, 0)); // Orange color
  pixels.show();
}

void turnSignalRightOn() {
  // Turn signal on
  pixels.setPixelColor(1, pixels.Color(70, 255, 0)); // Orange color
  pixels.setPixelColor(2, pixels.Color(70, 255, 0)); // Orange color
  pixels.show();
}

void turnSignalRightOff() {
  // Turn signal on
  pixels.setPixelColor(1, pixels.Color(0, 0, 0)); // Orange color
  pixels.setPixelColor(2, pixels.Color(0, 0, 0)); // Orange color
  pixels.show();
}

void brakeSignalOn() {
  // Turn signal on
  pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // Orange color
  pixels.setPixelColor(1, pixels.Color(0, 255, 0)); // Orange color
  pixels.show();
}
void brakeSignalOff() {
  // Turn signal on
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // Orange color
  pixels.setPixelColor(1, pixels.Color(0, 0, 0)); // Orange color
  pixels.show();
}

void frontLights(){
  pixels.setPixelColor(3, pixels.Color(255, 255, 255)); // Orange color
  pixels.setPixelColor(2, pixels.Color(255, 255, 255)); // Orange color
  pixels.show();
}