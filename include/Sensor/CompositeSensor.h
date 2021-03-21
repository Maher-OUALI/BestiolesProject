#ifndef _COMPOSITE_SENSOR_H_
#define _COMPOSITE_SENSOR_H_

#include "Sensor.h"
#include "Ears.h"
#include "Eyes.h"


class CompositeSensor: public Sensor
{

    private:
    Ears* ear;
    Eyes* eye;
public:
    CompositeSensor()
    {
        ear =  new Ears() ;
        eye =  new Eyes();
    }
    bool canSense(const Bestiole &b2) override;

    CompositeSensor* clone(Bestiole* ownr) ;

    void Draw(UImg & support) override;

    void DrawCompositeSensor(UImg & support);

    void setOwner(Bestiole* ownr) override;

    ~CompositeSensor(){}


};


#endif