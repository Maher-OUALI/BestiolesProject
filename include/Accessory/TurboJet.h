#ifndef _TURBOJET_H_
#define _TURBOJET_H_
#include "UImg.h"

#include "Accessory.h"




class TurboJet:public Accessory
{


    
public:
    TurboJet():Accessory("TurboJet")
    {
        color_[0]=Colors::blue[0];
        color_[1]=Colors::blue[1];
        color_[2]=Colors::blue[2];


        speed_mod_=EnvConfig::sTurboJetMod;
        
    }
   // virtual double getSpeedMod(){return speed_mod_;}
    //virtual double getArmorMod(){return armor_mod_;}
    //virtual double getStealthMod(){return stealth_mod_;}
    TurboJet* clone(Bestiole* ownr) override;

    ~TurboJet(){}



};


#endif