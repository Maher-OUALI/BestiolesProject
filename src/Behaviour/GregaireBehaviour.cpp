#include "GregaireBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>


GregaireBehaviour* GregaireBehaviour::clone(Bestiole* ownr)
{
    return new GregaireBehaviour();
}


void GregaireBehaviour::calculateDir(Milieu & monMilieu)
{
    double orientation_moyenne;
    int size=0;

    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
        //bestiole different from itself
        if ((**it).getIdentite() != owner->getIdentite()){
            //check if bestiole can see target
            if(owner->jeTeVois(**it)){
                if(EnvConfig::sDebugVision)  cout<<*owner<<" can sense "<<**it<<std::endl;
                //sum all orientation
                orientation_moyenne += (**it).getOrientationRad();
                size += 1;
            }
            else
            {
            if(EnvConfig::sDebugVision)  cout<<"....................."<<std::endl;
            }
        }
    }
    if(size==0){
        //return same orientation
        angle_rad=owner->getOrientationRad();
    }else{
        //return average orientation
        angle_rad=orientation_moyenne/size;
    }
}
