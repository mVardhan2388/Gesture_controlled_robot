// Transmitter Code - Arduino Nano + ADXL335 + RF433 MHz Transmitter
const int xPin = A0;
const int yPin = A1;

void setup() {
  Serial.begin(9600);   // For debugging (optional)
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  // Determine direction based on thresholds
  char direction;

  if (xVal < 300) direction = 'L';  // Left
  else if (xVal > 700) direction = 'R';  // Right
  else if (yVal < 300) direction = 'F';  // Forward
  else if (yVal > 700) direction = 'B';  // Backward
  else direction = 'S';  // Stop

  Serial.write(direction);  // Send command over RF

  delay(100);  // Short delay to prevent flooding
}
