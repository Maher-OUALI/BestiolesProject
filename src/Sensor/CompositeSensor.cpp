#include "CompositeSensor.h"
#include "Bestiole.h"



bool CompositeSensor::canSense(const Bestiole &b2)
{
    return ( eye->canSense(b2) || ear->canSense(b2));
}

void CompositeSensor::setOwner(Bestiole* ownr) 
{
    owner=ownr;
    eye->setOwner(ownr);
    ear->setOwner(ownr);
}

CompositeSensor* CompositeSensor::clone(Bestiole* ownr)
{
    return new CompositeSensor(*this);
}

void CompositeSensor::Draw(UImg & support)
{
    DrawCompositeSensor(support);
}
void CompositeSensor::DrawCompositeSensor(UImg & support)
{
    
   if(EnvConfig::sDrawSensors)
   {
       ear->DrawHearingCircle(support);
       eye->DrawVisionCone(support)  ;
    }
}
