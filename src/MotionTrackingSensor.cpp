
//#include <Adafruit_MPU6050.h>
#include <Adafruit_MPU6050.h>
#include "MotionTrackingSensor.h"

MotionTrackingSensor::MotionTrackingSensor() {
    motionTrackingSensor = new Adafruit_MPU6050();
}

void MotionTrackingSensor::begin() const {
    Serial.println("Initializing MPU6050...");
    if (!motionTrackingSensor->begin()) {
        Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
        while (1) {
            delay(10);
        };
    }
    Serial.println("MPU6050 is initialized");

    // // Calibrate gyroscope. The calibration must be at rest.
    // Serial.println("Calibrating gyroscope...");
    // motionTrackingSensor->calibrateGyro();

    // // Set threshold sensibility. Default 3.
    // motionTrackingSensor->setThreshold(3);

    motionTrackingSensor->setAccelerometerRange(MPU6050_RANGE_8_G);
    motionTrackingSensor->setGyroRange(MPU6050_RANGE_500_DEG);
    motionTrackingSensor->setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void MotionTrackingSensor::log() const {

    double aX, aY, aZ, wX, wY, wZ, temp, altitude, baseline, pressure;


    sensors_event_t a, g, t;
    motionTrackingSensor->getEvent(&a, &g, &t);
    aX = a.acceleration.x;
    aY = a.acceleration.y;
    aZ = a.acceleration.z;
    wX = g.gyro.x;
    wY = g.gyro.y;
    wZ = g.gyro.z;
    temp = t.temperature;
    // pressure = getPressure();
    // prevalt3 = prevalt2;
    // prevalt2 = prevalt1;
    // prevalt1 = altitude;  
    // altitude = bmp.altitude(pressure,baseline);

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" degC");
    Serial.print("Total Acceleration: ");
    Serial.println(pow(pow(aX, 2) + pow(aY, 2) + pow(aZ, 2), .5));
    Serial.print("Relative Altitude (meters): ");
    Serial.println(altitude);
    // Serial.println(agX);
    // Serial.println(agY);
    // Serial.println(agZ);


    Serial.println("");
}
