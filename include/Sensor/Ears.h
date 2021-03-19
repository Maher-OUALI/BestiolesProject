#ifndef _EARS_H_
#define _EARS_H_

#include "Sensor.h"


class Ears: public Sensor
{

    private:
    double detection_capacity;
    double max_dist;
public:
    Ears()
    {
        detection_capacity=1;
        max_dist=20;
    }
    bool canSense(const Bestiole &b2) override;

    Ears* clone(Bestiole* ownr) ;

    void Draw(UImg & support) override;

    void DrawHearingCircle(UImg & support);

    ~Ears(){}


};


#endif