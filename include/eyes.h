#ifndef _EYES_H_
#define _EYES_H_

#include "sensor.h"

class Eyes:Sensor
{

    
public:
    Eyes(double angle, double distance, double detectionCapacity)
    {
        
    }
    bool canSense(const Bestiole &b2) override;

    Eyes* clone(Bestiole* ownr) ;

    ~Eyes(){}


};


#endif