#include "PrevoyanteBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>



PrevoyanteBehaviour* PrevoyanteBehaviour::clone(Bestiole* ownr)
{
    return new PrevoyanteBehaviour();
}


void PrevoyanteBehaviour::calculateDir(Milieu & monMilieu)
{
    //initialize
    double min_dist=1000000;
    math::vector2 pos=math::vector2(-1,-1);
    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
        //bestiole different from itself
        if ((**it).getIdentite() != owner->getIdentite()){
            //check if bestiole can see target
            if(owner->jeTeVois(**it)){
                //update nearest bestiole position to the owner
                if(math::vector2::distance(owner->getPosition(),(**it).getPosition()) < min_dist){
                    pos = (**it).getPosition();
                }
            }
        }
    }
    if(pos==math::vector2(-1,-1)){
        angle_rad=owner->getOrientationRad();
    }else{
        angle_rad=atan2((pos-owner->getPosition())[1], (pos-owner->getPosition())[0]);
    }
}
