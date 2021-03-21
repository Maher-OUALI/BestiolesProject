#include "PsychoBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"

#include "randomGen.h"


template PsycBehvrs MyRandomGen::getRandomType<PsycBehvrs>(std::vector<PsycBehvrs>,std::vector<double>);

PsychoBehaviour* PsychoBehaviour::clone(Bestiole* ownr)
{
    return new PsychoBehaviour();
}

void PsychoBehaviour::setOwner(Bestiole* ownr)
{
    owner=ownr;
    dumbBehaviour_.setOwner(ownr);
    spinnerBehaviour_.setOwner(ownr);
}




void PsychoBehaviour::calculateDir(Milieu & monMilieu)
{
    if(MyRandomGen::IsTrueRandom(EnvConfig::sPsychoChangeBProb))
    {
        cout<<"Changing behaviour"<<endl;

        auto newBehaviour=MyRandomGen::getRandomType<PsycBehvrs>(std::vector<PsycBehvrs>({psychDumb,psychSpinner}),std::vector<double>({0.5,0.5}));
        if(newBehaviour==psychSpinner)currentBehaviour_=&spinnerBehaviour_;
        if(newBehaviour==psychDumb)currentBehaviour_=&dumbBehaviour_;
    }


    currentBehaviour_->calculateDir(monMilieu);
    angle_rad= currentBehaviour_->getAngleRad();
    speed=currentBehaviour_->getSpeed();
}