#ifndef _SHIELD_H_
#define _SHIELD_H_
#include "UImg.h"

#include "Accessory.h"




class Shield:public Accessory
{


    
public:
    Shield():Accessory("Shield")
    {
        color_[0]=Colors::brown[0];
        color_[1]=Colors::brown[1];
        color_[2]=Colors::brown[2];


        speed_mod_=EnvConfig::sShieldSpeedMod;
        armor_mod_=EnvConfig::sShieldArmorMod;
        
    }
   // virtual double getSpeedMod(){return speed_mod_;}
    //virtual double getArmorMod(){return armor_mod_;}
    //virtual double getStealthMod(){return stealth_mod_;}
    Shield* clone(Bestiole* ownr) override;

    ~Shield(){}



};


#endif
