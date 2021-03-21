#include "Ears.h"
#include "Bestiole.h"



bool Ears::canSense(const Bestiole &b2)
{
    
    double distance=math::vector2::distance(owner->getPosition(),b2.getPosition());
    if(max_dist>distance)
    {
        return true;
    }
    return false;
}

Ears* Ears::clone(Bestiole* ownr)
{
    return new Ears();
}

void Ears::Draw(UImg & support)
{
    DrawHearingCircle(support);
}
void Ears::DrawHearingCircle(UImg & support)
{
    
   if(EnvConfig::sDrawSensors)
   {
   double CircleSIze=max_dist;
   
   support.draw_circle(owner->getPosition()[0],owner->getPosition()[1],CircleSIze,owner->getColeur(),0.3);
    }
}