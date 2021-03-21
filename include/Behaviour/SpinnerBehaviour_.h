#ifndef _SPINNER_BEHAVIOUR_H_
#define _SPINNER_BEHAVIOUR_H_

#include "behaviour.h"



class SpinnerBehaviour:public Behaviour
{
    // private:
    //     Bestiole* owner;
    public:
    SpinnerBehaviour()
    {
        
    }
    void calculateDir(Milieu & monMilieu) override;

    SpinnerBehaviour* clone(Bestiole* ownr);
    ~SpinnerBehaviour(){}
};

#endif