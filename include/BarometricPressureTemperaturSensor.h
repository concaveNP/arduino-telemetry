
// BarometricPressureTemperaturSensor.h
#ifndef BAROMETRICPRESSURETEMPERATURSENSOR_H
#define BAROMETRICPRESSURETEMPERATURSENSOR_H

#include "BaseSensor.h"

// Forward-Declare instead of include-ing the header for the class
class Adafruit_BMP085; 

class BarometricPressureTemperaturSensor : public BaseSensor {
private:
    Adafruit_BMP085* barometricPressureTemperaturSensor;
public:
    BarometricPressureTemperaturSensor();
    void begin() const override;
    void log() const override;
};

#endif // BAROMETRICPRESSURETEMPERATURSENSOR_H
