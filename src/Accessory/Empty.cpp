#include "Empty.h"

Empty* Empty::clone(Bestiole* ownr)
{
    return new Empty();
}

void Empty::Draw(UImg & support)
{
   //Empty accessory draws nothing 
   //support.draw_circle(owner->getPosition()[0],owner->getPosition()[1],3.0,color_,1.0);
}
