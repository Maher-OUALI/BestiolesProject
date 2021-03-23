#ifndef _SHIELD_H_
#define _SHIELD_H_
#include "UImg.h"

#include "Accessory.h"




class Shield:public Accessory
{


    
public:
    Shield():Accessory("Eyes")
    {
        color_[0]=Colors::green[0];
        color_[1]=Colors::green[1];
        color_[2]=Colors::green[2];


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