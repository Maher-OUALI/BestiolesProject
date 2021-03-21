#ifndef _ACCESSORIE_H_
#define _ACCESSORIE_H_
#include "UImg.h"

#include "Accesorie.h"




class TurboJet:public Accesorie
{


    
public:
    TurboJet():Accesorie()
    {
        speed_mod_=EnvConfig::sTurboJetMod;
        
    }
   // virtual double getSpeedMod(){return speed_mod_;}
    //virtual double getArmorMod(){return armor_mod_;}
    //virtual double getStealthMod(){return stealth_mod_;}
    TurboJet* clone(Bestiole* ownr) override;

    ~TurboJet(){}



};


#endif