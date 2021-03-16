#ifndef _EYES_H_
#define _EYES_H_

#include "sensor.h"


class Eyes: public Sensor
{

    private:
    double detection_capacity;
    double fov_deg;
    double max_dist;
public:
    Eyes()
    {
        fov_deg=45;
        max_dist=20;
        detection_capacity=1;
    }
    bool canSense(const Bestiole &b2) override;

    Eyes* clone(Bestiole* ownr) ;

    void Draw(UImg & support) override;

    void DrawVisionCone(UImg & support);

    ~Eyes(){}


};


#endif