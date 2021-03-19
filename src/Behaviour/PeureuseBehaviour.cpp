#include "PeureuseBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>


PeureuseBehaviour* PeureuseBehaviour::clone(Bestiole* ownr)
{
    return new PeureuseBehaviour();
}


void PeureuseBehaviour::calculateDir(Milieu & monMilieu)
{
    if(monMilieu.nbVoisins(owner)>MAX_NEIGHBORS){

        double orientation_moyenne;
        int size=0;
        
        for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
            //bestiole different from itself
            if ((**it).getIdentite() != owner->getIdentite()){
                //check if bestiole can see target
                if(owner->jeTeVois(**it)){
                    //sum all orientation
                    orientation_moyenne += (**it).getOrientationRad();
                    size += 1;
                }
            }
        }

        //return the opposite of average orientation
        angle_rad=-orientation_moyenne/size;
        speed=SPEED_PEUREUSE_FACTOR;
        isEscaping=true;

    }else{
        if(isEscaping){
            speed=1.0;
            isEscaping=false;
        }
        angle_rad=owner->getOrientationRad();
    }
}