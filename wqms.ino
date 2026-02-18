// Define the analog pin connected to the Turbidity sensor (using A1)
#define TurbiditySensorPin A1

// Analog reference voltage (V) - typical for 5V Arduino boards
const float VREF = 5.0; 

void setup() {
  Serial.begin(9600);
  Serial.println("Turbidity Sensor Test Ready");
}

void loop() {
  // 1. Read the raw analog value (0 to 1023)
  int rawValue = analogRead(TurbiditySensorPin);

  // 2. Convert the raw value to voltage (0.00V to 5.00V)
  // Voltage (V) = Analog reading * (Reference voltage / ADC resolution)
  float voltage = rawValue * (VREF / 1024.0);

  // 3. Print the raw and voltage readings
  Serial.print("Raw ADC Value: ");
  Serial.print(rawValue);
  
  Serial.print("\tVoltage: ");
  Serial.print(voltage, 2);
  Serial.print("V");
  
  // NOTE on Turbidity: The voltage output is INVERSELY proportional to turbidity.
  // Higher Voltage = Clearer Water (Lower NTU)
  // Lower Voltage = Cloudier Water (Higher NTU)
  
  // To get an NTU value, you must use a calibration curve (like the one shown below).
  // For now, simply observe the voltage change.

  Serial.println();
  
  delay(500); // Wait for half a second before the next reading
}