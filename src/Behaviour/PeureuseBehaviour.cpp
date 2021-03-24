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
    if(monMilieu.nbVoisins(owner)>PeureuseBehaviour::max_neighbors){

        double orientation_moyenne;
        int size=0;
        
        for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
            //bestiole different from itself
            if ((**it).getIdentite() != owner->getIdentite()){
                //check if bestiole can see target
                if(owner->jeTeVois(**it)){
                    if(EnvConfig::sDebugVision)  cout<<*owner<<" can sense "<<**it<<std::endl;
                    //sum all orientation
                    math::vector2 relativePos=((**it).getPosition())-(owner->getPosition());
                    double relativeAngle =math::deg2Rad(relativePos.angleDeg());
                    //orientation_moyenne += (**it).getOrientationRad();
                    orientation_moyenne += relativeAngle;
                    size += 1;
                }
                else
                {
                if(EnvConfig::sDebugVision)  cout<<"....................."<<std::endl;
                }
            }
        }

        //return the opposite of average orientation
        angle_rad=M_PI+(orientation_moyenne/size);
        //angle_rad=M_PI+owner->getOrientationRad();
        speed=PeureuseBehaviour::speed_factor;
        isEscaping=true;

    }else{
        if(isEscaping){
            speed=1.0;
            isEscaping=false;
        }
        angle_rad=owner->getOrientationRad();
    }
}
