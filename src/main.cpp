#include <SPI.h>
#include <Arduino.h>
#include <Wire.h>
#include "BarometricPressureTemperaturSensor.h"
#include "MotionTrackingSensor.h"

// Constants
const int LOOP_DELAY = 1000; // in milliseconds - so, 1 second

// Sensors
BarometricPressureTemperaturSensor barometricPressureTemperaturSensor;
MotionTrackingSensor motionTrackingSensor;

void setup() {

  // TODO: lookup what this class does
  Wire.begin();

  // Set the communication rate and start.  Order is important as the sensors will use the global Serial object.
  Serial.begin(9600);

  // Start the sensors
  barometricPressureTemperaturSensor.begin();
  motionTrackingSensor.begin();

}

void loop() {

  // Log the sensors input
  barometricPressureTemperaturSensor.log();
  motionTrackingSensor.log();

  // Put in a sleep to keep from a hard loop
  delay(LOOP_DELAY);

}