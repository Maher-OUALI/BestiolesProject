#ifndef _EARS_H_
#define _EARS_H_

#include "Sensor.h"
#include "randomGen.h"


class Ears: public Sensor
{

    private:
    double detection_capacity;
    double max_dist;
public:
    Ears():Sensor("Ears")
    {
        detection_capacity=MyRandomGen::RandomDouble(EnvConfig::sMinHearingIntensity , EnvConfig::sMaxHearingIntensity);
        max_dist=MyRandomGen::RandomDouble(EnvConfig::sMinHearingDist , EnvConfig::sMaxHearingDist);
    }
    
    Ears(const Ears &ear):Sensor("Ears")
    {
        max_dist=ear.max_dist;
        detection_capacity=ear.detection_capacity;
    }

    bool canSense(const Bestiole &b2) override;

    Ears* clone(Bestiole* ownr) ;


    void Draw(UImg & support) override;

    void DrawHearingCircle(UImg & support);

    ~Ears(){}


};


#endif
