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
    
    Eyes( Eyes &eye):Sensor("Eyes")
    {
        fov_deg=eye.fov_deg;
        max_dist=eye.max_dist;
        detection_capacity=eye.detection_capacity;
    }
    
    bool canSense(const Bestiole &b2) override;

    Eyes* clone(Bestiole* ownr) ;



    void Draw(UImg & support) override;

    void DrawVisionCone(UImg & support);

    ~Eyes(){}


};


#endif
