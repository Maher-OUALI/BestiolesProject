#ifndef _EYES_H_
#define _EYES_H_

#include "Sensor.h"
#include "randomGen.h"


class Eyes: public Sensor
{

    private:
    double detection_capacity;
    double fov_deg;
    double max_dist;
public:
    Eyes():Sensor("Eyes")
    {
        fov_deg=MyRandomGen::RandomDouble(EnvConfig::sMinVisionAngle , EnvConfig::sMaxVisionAngle);
        max_dist=MyRandomGen::RandomDouble(EnvConfig::sMinVisionDist , EnvConfig::sMaxVisionDist);
        detection_capacity=MyRandomGen::RandomDouble(EnvConfig::sMinVisionIntensity , EnvConfig::sMaxVisionIntensity);
    }
    bool canSense(const Bestiole &b2) override;

    Eyes* clone(Bestiole* ownr) ;



    void Draw(UImg & support) override;

    void DrawVisionCone(UImg & support);

    ~Eyes(){}


};


#endif