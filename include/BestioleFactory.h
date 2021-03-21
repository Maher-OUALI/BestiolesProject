#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include <memory>

#include "Bestiole.h"

#include "SpinnerBehaviour.h"
#include "DumbBehaviour.h"
#include "BraindeadBehaviour.h"
#include "Eyes.h"
#include "Ears.h"
#include "CompositeSensor.h"
#include "Milieu.h"
#include "TurboJet.h"



class BestioleFactory
{
   
   public:
     // BestioleFactory(){}
 static std::shared_ptr<Bestiole> createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor,enum_Accesorie selected_accesorie);
   static std::shared_ptr<Bestiole> createBestioleClone(const Bestiole & b);
   static std::shared_ptr<Bestiole> createRandomBestiole();
   //,bool register_best=false
   static Milieu *milieu_;


   private:

   
   static   Behaviour* createBehaviour(enum_Behavior selected_behaviour);

   static   Sensor* createSensor(enum_Sensor selected_sensor);

   static Accesorie* createAccesorie(enum_Accesorie selected_accesorie);
};



#endif