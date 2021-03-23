#ifndef _SHIELD_H_
#define _SHIELD_H_
#include "UImg.h"

#include "Accessory.h"




class Shield:public Accessory
{


    
public:
    Shield():Accessory("Eyes")
    {
        speed_mod_=0.5;
        armor_mod_=EnvConfig::sShieldArmorMod;
        
    }
   // virtual double getSpeedMod(){return speed_mod_;}
    //virtual double getArmorMod(){return armor_mod_;}
    //virtual double getStealthMod(){return stealth_mod_;}
    Shield* clone(Bestiole* ownr) override;

    ~Shield(){}



};


#endif