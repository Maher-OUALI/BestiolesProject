#include "Accessory.h"
#include "Bestiole.h"

void Accessory::Draw(UImg & support)
{
    

   support.draw_circle(owner->getPosition()[0],owner->getPosition()[1],3.0,color_,1.0);

}