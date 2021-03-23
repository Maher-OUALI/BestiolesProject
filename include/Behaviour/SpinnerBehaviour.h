#ifndef _SPINNER_BEHAVIOUR_H_
#define _SPINNER_BEHAVIOUR_H_

#include "Behaviour.h"



class SpinnerBehaviour:public Behaviour
{
    // private:
    //     Bestiole* owner;
    public:
    SpinnerBehaviour():Behaviour("Spinner")
    {
        
    }
    void calculateDir(Milieu & monMilieu) override;

    SpinnerBehaviour* clone(Bestiole* ownr);
    ~SpinnerBehaviour(){}
};

#endif