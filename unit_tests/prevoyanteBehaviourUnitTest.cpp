#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"


#include <iostream>
#include <string>     // std::string, std::stof

#include <map>
//#include "randomGen.h"
#include "Config.h"

#include "vec2.h"



#include "BestioleFactory.h"

using namespace std;






enum MyEnum { AA=0 , BB=1  };// Deleete

int prevoyanteBehaviourUnitTest()
{
   const char* fname="config.txt";
   EnvConfig::ReadConfFile(fname);



   Aquarium       ecosysteme( 640, 480, 30 );
   BestioleFactory::milieu_=&ecosysteme.getMilieu();

   //create a kamikaze bestiole
   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Prevoyante,enum_Sensor::Eyes);
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-100,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);
   
   //create two other bestiole moving the opposite direction
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes);
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+70,ecosysteme.getMilieu().getHeight()/2.0+10);
   b2->setOrientationDeg(180.0);

   Bestiole* b3=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes);
   b3->setCoords(ecosysteme.getMilieu().getWidth()/2.0+70,ecosysteme.getMilieu().getHeight()/2.0-10);
   b3->setOrientationDeg(180.0);

   
   ecosysteme.run();


   std::cout<<"End of program"<<std::endl;
   return 0;

}