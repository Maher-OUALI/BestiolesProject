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
        color_[0]=Colors::blue[0];
        color_[1]=Colors::blue[1];
        color_[2]=Colors::blue[2];
    }
    void calculateDir(Milieu & monMilieu) override;

    PrevoyanteBehaviour* clone(Bestiole* ownr);
    ~PrevoyanteBehaviour(){}
};

#endif
