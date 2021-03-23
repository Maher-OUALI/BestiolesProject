#ifndef _PREVOYANTE_BEHAVIOUR_H_
#define _PREVOYANTE_BEHAVIOUR_H_

#include "Behaviour.h"



class PrevoyanteBehaviour: public Behaviour
{
    //private:
    //    Bestiole* owner;     
    public:
    PrevoyanteBehaviour():Behaviour("Oracle")
    {
        
    }
    void calculateDir(Milieu & monMilieu) override;

    PrevoyanteBehaviour* clone(Bestiole* ownr);
    ~PrevoyanteBehaviour(){}
};

#endif
