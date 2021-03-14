#ifndef _EARS_H_
#define _EARS_H_

#include "sensor.h"

class Ears:Sensor
{

    
public:
    Ears(double angle, double distance, double detectionCapacity)
    {
        
    }
    bool canSense(const Bestiole &b2) override;

    Ears* clone(Bestiole* ownr) ;

    ~Ears(){}


};

#endif