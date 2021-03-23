#ifndef _BEHAVIOUR_H_
#define _BEHAVIOUR_H_

#include "Component.h"




class Behaviour: public Component
{
    friend Bestiole;
    
    protected :

         double angle_rad;
         double speed;

    public:
        Behaviour(const std::string name):Component(name)
        {
            speed=1.0;
            angle_rad=0.0;
        }


        virtual void calculateDir(Milieu & monMilieu)= 0;
        virtual Behaviour* clone(Bestiole* ownr)=0;

        double getAngleRad(){return angle_rad;}
        double getSpeed(){return speed;}


        virtual ~Behaviour(){}
};

#endif