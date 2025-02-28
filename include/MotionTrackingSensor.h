
// MotionTrackingSensor.h
#ifndef MOTIONTRACKINGSENSOR_H
#define MOTIONTRACKINGSENSOR_H

#include "BaseSensor.h"

// Forward-Declare instead of include-ing the header for the class
class Adafruit_MPU6050; 

class MotionTrackingSensor : public BaseSensor {
private:
    Adafruit_MPU6050* motionTrackingSensor;
public:
    MotionTrackingSensor();
    void begin() const override;
    void log() const override;
};

#endif // MOTIONTRACKINGSENSOR_H
