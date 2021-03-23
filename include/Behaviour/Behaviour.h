#ifndef _BEHAVIOUR_H_
#define _BEHAVIOUR_H_

#include "Component.h"




class Behaviour: public Component
{
    friend Bestiole;
    
    protected :

         double angle_rad;
         double speed;
         T    color_[3];

    public:
        Behaviour(const std::string name):Component(name)
        {
            color_[0]=Colors::black[0];
            color_[1]=Colors::black[1];
            color_[2]=Colors::black[2];
            
            
            speed=1.0;
            angle_rad=0.0;
        }


        virtual void calculateDir(Milieu & monMilieu)= 0;
        virtual Behaviour* clone(Bestiole* ownr)=0;

        double getAngleRad(){return angle_rad;}
        double getSpeed(){return speed;}
        T* getColor(){return color_;}


        virtual ~Behaviour(){}
};

#endif
