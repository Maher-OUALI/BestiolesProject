#ifndef _PEUREUSE_BEHAVIOUR_H_
#define _PEUREUSE_BEHAVIOUR_H_

#include "Behaviour.h"



class PeureuseBehaviour: public Behaviour
{
    private:
        const int MAX_NEIGHBORS=0;
        const double SPEED_PEUREUSE_FACTOR=3.0;
    //    Bestiole* owner;
        bool isEscaping=false;
    public:
    PeureuseBehaviour()
    {
        
    }
    void calculateDir(Milieu & monMilieu) override;

    PeureuseBehaviour* clone(Bestiole* ownr);
    ~PeureuseBehaviour(){}
};

#endif
