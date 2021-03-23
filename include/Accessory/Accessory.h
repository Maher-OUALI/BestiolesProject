#ifndef _ACCESSORIEE_H_
#define _ACCESSORIEE_H_
#include "UImg.h"

#include "Component.h"



class Accessory:public Component
{

protected:
double speed_mod_;
double armor_mod_;
double stealth_mod_;
    
public:
    Accessory(const std::string name):Component(name)
    {
        speed_mod_=1.0;
        armor_mod_=1.0;
        stealth_mod_=1.0;
    }
    virtual double getSpeedMod(){return speed_mod_;}
    virtual double getArmorMod(){return armor_mod_;}
    virtual double getStealthMod(){return stealth_mod_;}
    virtual Accessory* clone(Bestiole* ownr)=0;

    virtual ~Accessory(){}



};


#endif