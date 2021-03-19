#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include <memory>

#include "Bestiole.h"

#include "SpinnerBehaviour.h"
#include "DumbBehaviour.h"
#include "BraindeadBehaviour.h"
#include "PeureuseBehaviour.h"
#include "PrevoyanteBehaviour.h"
#include "KamikazeBehaviour.h"
#include "GregaireBehaviour.h"

#include "CompositeSensor.h"
#include "Eyes.h"
#include "Ears.h"


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