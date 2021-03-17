#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include <memory>

#include "Bestiole.h"

#include "spinnerBehaviour.h"
#include "dumbBehaviour.h"
#include "braindeadBehaviour.h"
#include "eyes.h"
#include "ears.h"
#include "compositeSensor.h"
#include "Milieu.h"
#include "turboJet.h"



class BestioleFactory
{
   
   public:
     // BestioleFactory(){}
 static Bestiole* createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor,enum_Accesorie selected_accesorie);
   static Bestiole* createBestioleClone(const Bestiole & b);
   //,bool register_best=false
   static Milieu *milieu_;


   private:

   
   static   Behaviour* createBehaviour(enum_Behavior selected_behaviour);

   static   Sensor* createSensor(enum_Sensor selected_sensor);

   static Accesorie* createAccesorie(enum_Accesorie selected_accesorie);
};



#endif