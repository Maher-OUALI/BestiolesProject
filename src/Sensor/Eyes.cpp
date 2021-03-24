#include "Eyes.h"
#include "Bestiole.h"



bool Eyes::canSense(const Bestiole &b2)
{
    math::vector2 relativePos=(b2.getPosition())-(owner->getPosition());
    double relativeAngle =relativePos.angleDeg();
    double ownerAngle=owner->getAngleDeg();
    double finalAngle=math::constrainAngle(relativeAngle-ownerAngle);
    double distance=math::vector2::distance(owner->getPosition(),b2.getPosition());
    if(finalAngle < fov_deg   && finalAngle > -fov_deg && max_dist>distance && b2.getFinalStealth()<detection_capacity )
    {
        return true;
    }
    return false;
}

Eyes* Eyes::clone(Bestiole* ownr)
{
    return new Eyes(*this);
}




void Eyes::Draw(UImg & support)
{
    DrawVisionCone(support);
}
void Eyes::DrawVisionCone(UImg & support)
{
    
   if(EnvConfig::sDrawSensors)
   {
   double triangleSIze=max_dist/cos(fov_deg*M_PI/180);
   math::vector2 triangPoint1=math::vector2(1,0).rot(fov_deg)*triangleSIze;
   math::vector2 triangPoint2=math::vector2(1,0).rot(-fov_deg)*triangleSIze;
   
   triangPoint1=triangPoint1.rot(math::rad2Deg(-(owner->getOrientationRad())))+owner->getPosition();
   triangPoint2=triangPoint2.rot(math::rad2Deg(-(owner->getOrientationRad())))+owner->getPosition();
   support.draw_triangle(owner->getPosition()[0],owner->getPosition()[1],triangPoint1[0],triangPoint1[1],triangPoint2[0],triangPoint2[1],owner->getColeur(),0.3);
}
}
