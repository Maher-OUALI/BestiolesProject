#ifndef _BESTIOLE_FACTORY_H_
#define _BESTIOLE_FACTORY_H_

#include "Bestiole.h"
#include "spinnerBehaviour.h"
#include "dumbBehaviour.h"
#include "braindeadBehaviour.h"
#include "eyes.h"

class BestioleFactory
{
   public:
      Bestiole * createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor);

      Behaviour* createBehaviour(enum_Behavior selected_behaviour);

       Sensor* createSensor(enum_Sensor selected_sensor);
};



#endif