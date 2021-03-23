#ifndef _PEUREUSE_BEHAVIOUR_H_
#define _PEUREUSE_BEHAVIOUR_H_

#include "Behaviour.h"



class PeureuseBehaviour: public Behaviour
{
    private:
        int max_neighbors;
        double speed_factor;
        bool isEscaping;
    public:
        PeureuseBehaviour():Behaviour("Lazy")
        {
            color_[0]=Colors::yellow[0];
            color_[1]=Colors::yellow[1];
            color_[2]=Colors::yellow[2];

            max_neighbors=EnvConfig::sMaxNeighborsPeureuse;
            speed_factor=EnvConfig::sRunawayFactorPeureuse;
            isEscaping=false;
        }
        void calculateDir(Milieu & monMilieu) override;

        PeureuseBehaviour* clone(Bestiole* ownr);
        ~PeureuseBehaviour(){}
};

#endif
