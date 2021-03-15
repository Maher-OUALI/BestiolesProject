#include "dumbBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"


DumbBehaviour* DumbBehaviour::clone(Bestiole* ownr)
{
    return new DumbBehaviour();
}


void DumbBehaviour::calculateDir(Milieu & monMilieu)
{
    angle_rad= (owner->getOrientationRad()) ;
}