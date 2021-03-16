#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include <memory>

#include "Bestiole.h"


#include "Milieu.h"



class BestioleFactory
{
   
   public:
     // BestioleFactory(){}
   static   Bestiole* createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor);
   static Bestiole* createBestioleClone(const Bestiole & b);
   static Milieu *milieu_;


   private:

   
   static   Behaviour* createBehaviour(enum_Behavior selected_behaviour);

   static   Sensor* createSensor(enum_Sensor selected_sensor);
};



#endif