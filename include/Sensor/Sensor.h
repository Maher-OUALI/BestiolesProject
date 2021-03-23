#ifndef _SENSOR_H_
#define _SENSOR_H_
#include "UImg.h"

#include "Component.h"



class Sensor:public Component
{

    
public:
    
    Sensor(const std::string name):Component(name)
    {
        
    }
    virtual bool canSense(const Bestiole &b2)=0;
    virtual Sensor* clone(Bestiole* ownr)=0;

    virtual ~Sensor();



};


#endif