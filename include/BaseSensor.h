
// BaseSensor.h
#ifndef BASESENSOR_H
#define BASESENSOR_H

class BaseSensor {
public:
    virtual ~BaseSensor() {}
    virtual void begin() const = 0; // Pure virtual function
    virtual void log() const = 0; // Pure virtual function
};

#endif // BASESENSOR_H