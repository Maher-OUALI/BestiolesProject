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
    kamikazeBehaviour_.setOwner(ownr);
    prevoyanteBehaviour_.setOwner(ownr);
    peureuseBehaviour_.setOwner(ownr);
    gregaireBehaviour_.setOwner(ownr);
    braindeadBehaviour_.setOwner(ownr);
}




void PsychoBehaviour::calculateDir(Milieu & monMilieu)
{
    if(MyRandomGen::IsTrueRandom(EnvConfig::sPsychoChangeBProb))
    {
        cout<<"Changing behaviour"<<endl;

        auto newBehaviour=MyRandomGen::getRandomType<PsycBehvrs>(std::vector<PsycBehvrs>({psychDumb,psychSpinner,psychBraindead,psychKamikaze,psychPeureuse,psychPrevoyante,psychGregaire}),std::vector<double>({0.5,0.5}));
        if(newBehaviour==psychSpinner)currentBehaviour_=&spinnerBehaviour_;
        if(newBehaviour==psychDumb)currentBehaviour_=&dumbBehaviour_;
        if(newBehaviour==psychBraindead)currentBehaviour_=&braindeadBehaviour_;
        if(newBehaviour==psychKamikaze)currentBehaviour_=&kamikazeBehaviour_;
        if(newBehaviour==psychPeureuse)currentBehaviour_=&peureuseBehaviour_;
        if(newBehaviour==psychPrevoyante)currentBehaviour_=&prevoyanteBehaviour_;
        if(newBehaviour==psychGregaire)currentBehaviour_=&gregaireBehaviour_;

    }


    owner->getColeur()[0]=currentBehaviour_->getColor()[0];
    owner->getColeur()[1]=currentBehaviour_->getColor()[1];
    owner->getColeur()[2]=currentBehaviour_->getColor()[2];
    currentBehaviour_->calculateDir(monMilieu);
    angle_rad= currentBehaviour_->getAngleRad();
    speed=currentBehaviour_->getSpeed();
}
