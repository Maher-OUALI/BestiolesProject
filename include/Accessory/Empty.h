#ifndef _EMPTY_H_
#define _EMPTY_H_
#include "UImg.h"

#include "Accessory.h"
#include "randomGen.h"




class Empty:public Accessory
{


    
public:
    Empty():Accessory("Empty")
    {

    }
   
    Empty* clone(Bestiole* ownr) override;
    void Draw(UImg & support) override;
    ~Empty(){}
};


#endif
