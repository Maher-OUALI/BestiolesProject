#ifndef _DUMB_BEHAVIOUR_H_
#define _DUMB_BEHAVIOUR_H_

#include "Behaviour.h"



class DumbBehaviour:Behaviour
{
    // private:
    // Bestiole* owner;
    public:
    DumbBehaviour():Behaviour()
    {
    }
    void calculateDir(Milieu & monMilieu) override;

    DumbBehaviour* clone(Bestiole* ownr);

    ~DumbBehaviour(){}
};

#endif