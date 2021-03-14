#include "eyes.h"
#include "Bestiole.h"



bool Eyes::canSense(const Bestiole &b2)
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

Eyes* Eyes::clone(Bestiole* ownr)
{
    return new Eyes();
}