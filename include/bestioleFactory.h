#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include <memory>

#include "Bestiole.h"
#include "spinnerBehaviour.h"
#include "dumbBehaviour.h"
#include "braindeadBehaviour.h"
#include "eyes.h"

#include "Milieu.h"



class BestioleFactory
{
   
   public:
     // BestioleFactory(){}
   static   std::shared_ptr<Bestiole> createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor);
   static shared_ptr<Bestiole> createBestioleClone(const Bestiole & b);
   static Milieu *milieu_;


   private:

   
   static   Behaviour* createBehaviour(enum_Behavior selected_behaviour);

   static   Sensor* createSensor(enum_Sensor selected_sensor);
};



#endif