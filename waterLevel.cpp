// Pin definitions for LEDs
const int greenLedPin = 2;
const int yellowLedPin = 3;
const int redLedPin = 4;

// Pin definition for water level detection sensor
const int waterLevelSensorPin = A0;

void setup() {
  // Initialize LED pins as OUTPUT
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Start serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the water level sensor
  int waterLevel = analogRead(waterLevelSensorPin);

  // Map the analog value to water level categories
  if (waterLevel >= 800) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  } else if (waterLevel >= 400) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  }

  // Print water level value for debugging (optional)
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  delay(1000); // Adjust the delay time as needed
}
