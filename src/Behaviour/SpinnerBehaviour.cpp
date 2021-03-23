#include "SpinnerBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"


SpinnerBehaviour* SpinnerBehaviour::clone(Bestiole* ownr)
{
    return new SpinnerBehaviour();
}


void SpinnerBehaviour::calculateDir(Milieu & monMilieu)
{
    angle_rad= (owner->getOrientationRad()+math::deg2Rad(10)) ;
    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it )
    if ((*it).get()!=owner)
    {
        if(owner->jeTeVois(**it) ){
            
            
              if(EnvConfig::sDebugVision)  {
                  cout<<*owner<<" can see "<<**it<<std::endl;
                  //cout<<(*it).get()->getFinalStealth()<<std::endl;
                  //cout<<owner->getSensor()->cap()<<std::endl;
              }
            
        }
        else
        {
          if(EnvConfig::sDebugVision)  cout<<"....................."<<std::endl;
        }
    }
}