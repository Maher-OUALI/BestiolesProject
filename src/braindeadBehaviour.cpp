#include "braindeadBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"



BraindeadBehaviour* BraindeadBehaviour::clone(Bestiole* ownr)
{
    return new BraindeadBehaviour();
}


void BraindeadBehaviour::calculateDir(Milieu & monMilieu)
{
    angle_rad = owner->getOrientationRad() ;
    speed=0.0;

    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it )
    if ((*it).get()!=owner)
    {
        if(owner->jeTeVois(**it) ){
            
            
              if(EnvConfig::sDebugVision)  cout<<"B1 can see B2"<<std::endl;
            
        }
        else
        {
          if(EnvConfig::sDebugVision)  cout<<"....................."<<std::endl;
        }
    }
}