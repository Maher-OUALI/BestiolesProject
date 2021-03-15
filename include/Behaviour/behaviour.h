#ifndef _BEHAVIOUR_H_
#define _BEHAVIOUR_H_

#include "component.h"




class Behaviour: public Component
{
    friend Bestiole;
    
    protected :

         double angle_rad;
         double speed;

    public:
        Behaviour()
        {
            speed=1.0;
            angle_rad=0.0;
        }


        virtual void calculateDir(Milieu & monMilieu)= 0;
        virtual Behaviour* clone(Bestiole* ownr)=0;


        virtual ~Behaviour(){}
};

#endif