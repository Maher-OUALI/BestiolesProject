#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"


#include <iostream>
#include <string>     // std::string, std::stof

#include <map>
#include "randomGen.h"
#include "Config.h"

#include "vec2.h"



#include "BestioleFactory.h"

using namespace std;








template MyEnum MyRandomGen::getRandomType<MyEnum>(std::vector<MyEnum>,std::vector<double>);


int main()
{
   // for(int n=0; n<50; ++n)
   MyRandomGen::getRandomType<MyEnum>(std::vector<MyEnum>({AA,BB}),std::vector<double>({1.0,2.0}));
   //    std::cout<<"Random generator: "<<Random::IsTrueRandom(0.7)<<std::endl;

   // math::vector2 vec1=math::vector2(0,1);
   // math::vector2 vec2=math::vector2(1,1);

   // std::cout<<vec1<<endl;
   // std::cout<<vec2<<endl;
   // std::cout<<vec1.deg()<<endl;
   // std::cout<<math::vector2::angle(vec1,vec2)<<endl;
   // std::cout<<math::vector2::distance(vec1,vec2)<<endl;


   const char* fname="config.txt";
   EnvConfig::ReadConfFile(fname);



   Aquarium       ecosysteme( 640, 480, 30 );
   BestioleFactory::milieu_=&ecosysteme.getMilieu();

   //BestioleFactory factory=BestioleFactory(&ecosysteme.getMilieu());



   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Spinner,enum_Sensor::Eyes,enum_Accessory::Turbojet).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);
   

   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Braindead,enum_Sensor::Eyes,enum_Accessory::Cloak).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+40,ecosysteme.getMilieu().getHeight()/2.0);
   b2->setOrientationDeg(180.0);


   //Eyes dummySensor = Eyes();

   //cout<<dummySensor.getName()<<endl;

   

   //for ( int i = 1; i <= 10; ++i )
   //    BestioleFactory::createRandomBestiole();
    ecosysteme.run();

   std::cout<<"End of program"<<std::endl;
   return 0;

}
