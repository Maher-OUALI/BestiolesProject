#ifndef _TURBOJET_H_
#define _TURBOJET_H_
#include "UImg.h"

#include "Accessory.h"




class TurboJet:public Accessory
{


    
public:
    TurboJet():Accessory("TurboJet")
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