#ifndef _CLOAK_H_
#define _CLOAK_H_
#include "UImg.h"

#include "Accessory.h"




class Cloak:public Accessory
{


    
public:
    Cloak():Accessory("Cloak")
    {
        color_[0]=Colors::red[0];
        color_[1]=Colors::red[1];
        color_[2]=Colors::red[2];


        speed_mod_=0.5;
        stealth_mod_=EnvConfig::sCloakStealthMod;
        
    }
   // virtual double getSpeedMod(){return speed_mod_;}
    //virtual double getArmorMod(){return armor_mod_;}
    //virtual double getStealthMod(){return stealth_mod_;}
    Cloak* clone(Bestiole* ownr) override;

    ~Cloak(){}



};


#endif