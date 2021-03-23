#ifndef _BRAINDEAD_BEHAVIOUR_H_
#define _BRAINDEAD_BEHAVIOUR_H_

#include "Behaviour.h"




class BraindeadBehaviour:public Behaviour
{
    // private:
    //     Bestiole* owner;
    public:
    BraindeadBehaviour():Behaviour("BrainDead")
    {
    
    }
    void calculateDir(Milieu & monMilieu) override;

    BraindeadBehaviour* clone(Bestiole* ownr);
    ~BraindeadBehaviour(){}
};

#endif
