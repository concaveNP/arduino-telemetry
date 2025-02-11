#include <SPI.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1) {}
  }
}

void loop() {
  float temperature = bmp.readTemperature();
  long pressure = bmp.readPressure();
  float altitude = bmp.readAltitude();

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" Pa");

  Serial.print("Altitude = ");
  Serial.print(altitude);
  Serial.println(" meters");

  Serial.println("");

  delay(1000);
}