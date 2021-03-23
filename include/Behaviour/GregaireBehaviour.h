#ifndef _GREGAIRE_BEHAVIOUR_H_
#define _GREGAIRE_BEHAVIOUR_H_

#include "Behaviour.h"



class GregaireBehaviour: public Behaviour
{
    //private:
    //    Bestiole* owner;
    public:
    GregaireBehaviour():Behaviour("Greagaire")
    {
        color_[0]=Colors::green[0];
        color_[1]=Colors::green[1];
        color_[2]=Colors::green[2];
    }
    void calculateDir(Milieu & monMilieu) override;

    GregaireBehaviour* clone(Bestiole* ownr);
    ~GregaireBehaviour(){}
};

#endif
