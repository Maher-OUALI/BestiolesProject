#include "DumbBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"


DumbBehaviour* DumbBehaviour::clone(Bestiole* ownr)
{
    return new DumbBehaviour();
}


void DumbBehaviour::calculateDir(Milieu & monMilieu)
{
    angle_rad= (owner->getOrientationRad()) ;
    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it )
    if ((*it).get()!=owner)
    {
        if(owner->jeTeVois(**it) ){
            
            
              if(EnvConfig::sDebugVision)  cout<<*owner<<" can sense "<<**it<<std::endl;
              
            
        }
        else
        {
          if(EnvConfig::sDebugVision)  cout<<"....................."<<std::endl;
        }
        
    }
}