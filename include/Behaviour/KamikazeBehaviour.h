#ifndef _KAMIKAZE_BEHAVIOUR_H_
#define _KAMIKAZE_BEHAVIOUR_H_

#include "Behaviour.h"



class KamikazeBehaviour: public Behaviour
{
    //private:
    //    Bestiole* owner;
    public:
    KamikazeBehaviour():Behaviour("Kamikaze")
    {
        color_[0]=Colors::red[0];
        color_[1]=Colors::red[1];
        color_[2]=Colors::red[2];
    }
    void calculateDir(Milieu & monMilieu) override;

    KamikazeBehaviour* clone(Bestiole* ownr);
    ~KamikazeBehaviour(){}
};

#endif
