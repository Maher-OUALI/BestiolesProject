#ifndef _PEUREUSE_BEHAVIOUR_H_
#define _PEUREUSE_BEHAVIOUR_H_

#include "behaviour.h"



class PeureuseBehaviour:Behaviour
{
    private:
        Bestiole* owner;
        const int MAX_NEIGHBORS=100;
    public:
    PeureuseBehaviour()
    {
        
    }
    void calculateDir(Milieu & monMilieu) override;

    PeureuseBehaviour* clone(Bestiole* ownr);
    ~PeureuseBehaviour(){}
};

#endif