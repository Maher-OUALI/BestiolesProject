#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include <memory>

#include "Bestiole.h"

//including behaviours
#include "SpinnerBehaviour.h"
#include "DumbBehaviour.h"
#include "BraindeadBehaviour.h"
#include "PeureuseBehaviour.h"
#include "PrevoyanteBehaviour.h"
#include "KamikazeBehaviour.h"
#include "GregaireBehaviour.h"
#include "PsychoBehaviour.h"

//including sensors
#include "Eyes.h"
#include "Ears.h"
#include "CompositeSensor.h"
#include "Milieu.h"

//including accessories
#include "TurboJet.h"
#include "Cloak.h"
#include "Shield.h"
#include "Empty.h"



class BestioleFactory
{
   
   public:
     // BestioleFactory(){}
 static std::shared_ptr<Bestiole> createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor,enum_Accessory selected_accessory);
   static std::shared_ptr<Bestiole> createBestioleClone( Bestiole & b);
   static std::shared_ptr<Bestiole> createRandomBestiole();
   //,bool register_best=false
   static Milieu *milieu_;

   static   Behaviour* createRandomBehaviour();


   private:

   
   static   Behaviour* createBehaviour(enum_Behavior selected_behaviour);

   static   Sensor* createSensor(enum_Sensor selected_sensor);

   static Accessory* createAccessory(enum_Accessory selected_accessory);
};



#endif
