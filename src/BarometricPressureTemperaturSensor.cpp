
#include <Adafruit_BMP085.h>
#include "BarometricPressureTemperaturSensor.h"

BarometricPressureTemperaturSensor::BarometricPressureTemperaturSensor() {
    barometricPressureTemperaturSensor = new Adafruit_BMP085();
}

void BarometricPressureTemperaturSensor::begin() const {
  if (!barometricPressureTemperaturSensor->begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1) {};
  }
}

void BarometricPressureTemperaturSensor::log() const {
    float temperature = barometricPressureTemperaturSensor->readTemperature();
    long pressure = barometricPressureTemperaturSensor->readPressure();
    float altitude = barometricPressureTemperaturSensor->readAltitude();

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
}
