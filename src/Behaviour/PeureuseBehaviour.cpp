#include "peureuseBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>


PeureuseBehaviour* PeureuseBehaviour::clone(Bestiole* ownr)
{
    return new PeureuseBehaviour();
}


void PeureuseBehaviour::calculateDir(Milieu & monMilieu)
{
    if(monMilieu->nbVoisins(owner)>PeureuseBehaviour::MAX_NEIGHBORS){
        
    }else{
        angle_rad=owner->getOrientationRad()
    }
}