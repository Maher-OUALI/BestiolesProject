#ifndef _PSYCHO_BEHAVIOUR_H_
#define _PSYCHO_BEHAVIOUR_H_

#include "behaviour.h"
#include "dumbBehaviour.h"
#include "spinnerBehaviour.h"


enum  PsycBehvrs
{
    psychDumb,
    psychSpinner
};


class PsychoBehaviour:public Behaviour
{
     private:
     DumbBehaviour dumbBehaviour_;
     SpinnerBehaviour spinnerBehaviour_;
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