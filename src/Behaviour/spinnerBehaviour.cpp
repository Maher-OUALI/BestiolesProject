#include "spinnerBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"


SpinnerBehaviour* SpinnerBehaviour::clone(Bestiole* ownr)
{
    return new SpinnerBehaviour();
}


void SpinnerBehaviour::calculateDir(Milieu & monMilieu)
{
    angle_rad= (owner->getOrientationRad()+math::deg2Rad(10)) ;
}