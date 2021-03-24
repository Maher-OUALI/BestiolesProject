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

T    color_[3];
    
public:
    Accessory(const std::string name):Component(name)
    {
        color_[0]=Colors::black[0];
        color_[1]=Colors::black[1];
        color_[2]=Colors::black[2];

        //Base stats
        speed_mod_=1.0;
        armor_mod_=1.0;
        stealth_mod_=0.0;
    }
    virtual double getSpeedMod(){return speed_mod_;}
    virtual double getArmorMod(){return armor_mod_;}
    virtual double getStealthMod(){return stealth_mod_;}
    virtual Accessory* clone(Bestiole* ownr)=0;

    void Draw(UImg & support) override;

    virtual ~Accessory(){}



};


#endif