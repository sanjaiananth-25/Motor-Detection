# Motor Detection

An ESP32 vibration-monitoring prototype that reads an MPU6050 accelerometer, reports the acceleration and a simple vibration score over Serial, and turns on an LED when the score exceeds a threshold.

## Hardware and wiring

- ESP32 development board
- MPU6050 connected over I2C: SDA GPIO 21, SCL GPIO 22
- Indicator LED on GPIO 2 (use a current-limiting resistor if using an external LED)

## Library

Install an MPU6050 library that provides the `MPU6050` class and `initialize()`, `testConnection()`, and `getAcceleration()` methods. Library forks differ, so check that the installed API matches the sketch.

## Build and upload

1. Open `Motor_detection1a.ino` in Arduino IDE.
2. Select your ESP32 board and serial port.
3. Install the matching MPU6050 library.
4. Upload the sketch and open Serial Monitor at 115200 baud.

The sketch sums the absolute X, Y, and Z acceleration readings and compares the result with `threshold` (initially 20000). If the sum exceeds the threshold, GPIO 2 is driven HIGH and the serial output reports `FAULT DETECTED`; otherwise the output reports `NORMAL`. Tune the threshold for your sensor, mounting, and application.

## Limitations

This is a simple demonstration threshold, not a calibrated or safety-rated fault detector. The score includes static acceleration such as gravity and may require filtering or calibration for practical use.
