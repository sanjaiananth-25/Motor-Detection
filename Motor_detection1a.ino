#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

#define LED_PIN 2

long vibration = 0;
long threshold = 20000;   

void setup() {
  Serial.begin(115200);

  // Start I2C communication on ESP32
  Wire.begin(21, 22);

  // LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Initialize MPU6050
  mpu.initialize();

  // Check sensor connection
  if (mpu.testConnection()) {
    Serial.println("MPU6050 Connected Successfully");
  } else {
    Serial.println("MPU6050 Connection Failed");
  }
}

void loop() {
  int16_t ax, ay, az;

  // Read acceleration values from MPU6050
  mpu.getAcceleration(&ax, &ay, &az);

  // Calculate simple vibration magnitude
  vibration = abs(ax) + abs(ay) + abs(az);

  // Print values to Serial Monitor
  Serial.print("AX: ");
  Serial.print(ax);
  Serial.print("   AY: ");
  Serial.print(ay);
  Serial.print("   AZ: ");
  Serial.print(az);
  Serial.print("   Vibration: ");
  Serial.print(vibration);

  // Fault detection
  if (vibration > threshold) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("   --> FAULT DETECTED");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("   --> NORMAL");
  }

  delay(200);
}
