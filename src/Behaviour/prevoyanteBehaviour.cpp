#include "prevoyanteBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>


PrevoyanteBehaviour* PrevoyanteBehaviour::clone(Bestiole* ownr)
{
    return new PrevoyanteBehaviour();
}


void PrevoyanteBehaviour::calculateDir(Milieu & monMilieu)
{
    
}