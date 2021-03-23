#ifndef _EYES_H_
#define _EYES_H_

#include "Sensor.h"


class Eyes: public Sensor
{

    private:
    double detection_capacity;
    double fov_deg;
    double max_dist;
public:
    Eyes():Sensor("Eyes")
    {
        fov_deg=EnvConfig::sVisionAngle;
        max_dist=EnvConfig::sVisionDist;
        detection_capacity=EnvConfig::sVisionIntensity;
    }
    bool canSense(const Bestiole &b2) override;

    Eyes* clone(Bestiole* ownr) ;



    void Draw(UImg & support) override;

    void DrawVisionCone(UImg & support);

    ~Eyes(){}


};


#endif