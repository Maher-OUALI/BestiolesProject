#ifndef _PREVOYANTE_BEHAVIOUR_H_
#define _PREVOYANTE_BEHAVIOUR_H_

#include "behaviour.h"



class PrevoyanteBehaviour:Behaviour
{
    private:
        Bestiole* owner;
         
    public:
    PrevoyanteBehaviour()
    {
        
    }
    void calculateDir(Milieu & monMilieu) override;

    PrevoyanteBehaviour* clone(Bestiole* ownr);
    ~PrevoyanteBehaviour(){}
};

#endif