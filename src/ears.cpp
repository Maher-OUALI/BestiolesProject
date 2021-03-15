#include "ears.h"
#include "Bestiole.h"



bool Ears::canSense(const Bestiole &b2)
{
    math::vector2 relativePos=(b2.getPosition())-(owner->getPosition());
    double relativeAngle =relativePos.angleDeg();
    double ownerAngle=owner->getAngleDeg();
    double finalAngle=math::constrainAngle(relativeAngle-ownerAngle);
    if(finalAngle < 90.0   && finalAngle > -90.0)
    {
        return true;
    }
    return false;
}

Ears* Ears::clone(Bestiole* ownr)
{
    return new Ears(0,0,0);
}