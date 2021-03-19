#ifndef _KAMIKAZE_BEHAVIOUR_H_
#define _KAMIKAZE_BEHAVIOUR_H_

#include "Behaviour.h"



class KamikazeBehaviour:Behaviour
{
    //private:
    //    Bestiole* owner;
    public:
    KamikazeBehaviour()
    {
        
    }
    void calculateDir(Milieu & monMilieu) override;

    KamikazeBehaviour* clone(Bestiole* ownr);
    ~KamikazeBehaviour(){}
};

#endif