#ifndef _BEHAVIOUR_H_
#define _BEHAVIOUR_H_

#include "vec2.h"
#include "Config.h"


class Milieu;

class Bestiole;

class Behaviour
{
    friend Bestiole;
    
    protected :
         Bestiole* owner;
         double angle_rad;
         double speed;

    public:
        Behaviour()
        {
            speed=1.0;
            angle_rad=0.0;
        }

        void setOwner(Bestiole* ownr){owner= ownr;}
        virtual void calculateDir(Milieu & monMilieu)= 0;

        virtual Behaviour* clone(Bestiole* ownr)= 0;

        virtual ~Behaviour(){}
};

#endif