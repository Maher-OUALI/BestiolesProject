#ifndef _BRAINDEAD_BEHAVIOUR_H_
#define _BRAINDEAD_BEHAVIOUR_H_

#include "behaviour.h"




class BraindeadBehaviour:Behaviour
{
    // private:
    //     Bestiole* owner;
    public:
    BraindeadBehaviour()
    {
    
    }
    void calculateDir(Milieu & monMilieu) override;

    BraindeadBehaviour* clone(Bestiole* ownr);
    ~BraindeadBehaviour(){}
};

#endif