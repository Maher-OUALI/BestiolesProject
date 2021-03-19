#ifndef _PSYCHO_BEHAVIOUR_H_
#define _PSYCHO_BEHAVIOUR_H_

#include "Behaviour.h"
#include "DumbBehaviour.h"
#include "SpinnerBehaviour.h"
#include "KamikazeBehaviour.h"
#include "PrevoyanteBehaviour.h"
#include "PeureuseBehaviour.h"
#include "GregaireBehaviour.h"
#include "BraindeadBehaviour.h"


enum  PsycBehvrs
{
    psychDumb,
    psychSpinner, 
    psychBraindead,
    psychKamikaze,
    psychGregaire,
    psychPeureuse,
    psychPrevoyante
};


class PsychoBehaviour:public Behaviour
{
     private:
     DumbBehaviour dumbBehaviour_;
     SpinnerBehaviour spinnerBehaviour_;
     KamikazeBehaviour kamikazeBehaviour_;
     PrevoyanteBehaviour prevoyanteBehaviour_;
     PeureuseBehaviour peureuseBehaviour_;
     GregaireBehaviour gregaireBehaviour_;
     BraindeadBehaviour braindeadBehaviour_;
     Behaviour* currentBehaviour_;
    
    public:
    PsychoBehaviour():Behaviour()
    {
        
        currentBehaviour_= &spinnerBehaviour_;

    }
    void calculateDir(Milieu & monMilieu) override;

    void setOwner(Bestiole* ownr) override;

    PsychoBehaviour* clone(Bestiole* ownr);

    ~PsychoBehaviour(){}
};

#endif