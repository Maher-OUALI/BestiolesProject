#ifndef _SPINNER_BEHAVIOUR_H_
#define _SPINNER_BEHAVIOUR_H_

#include "Behaviour.h"



class SpinnerBehaviour:Behaviour
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