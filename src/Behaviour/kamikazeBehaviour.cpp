#include "kamikazeBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"


KamikazeBehaviour* KamikazeBehaviour::clone(Bestiole* ownr)
{
    return new KamikazeBehaviour();
}


void KamikazeBehaviour::calculateDir(Milieu & monMilieu)
{
    Bestiole & nearest_bestiole;
    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
        if (**it.getIdentite() == owner.getIdentite()){
            
        }
    }
     
    angle_rad=(owner->getOrientationRad()+math::deg2Rad(10)) ;
}