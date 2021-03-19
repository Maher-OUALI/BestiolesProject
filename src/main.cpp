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

int main()
{
   // for(int n=0; n<50; ++n)
   //    //getRandomType<MyEnum>(std::vector<MyEnum>({AA,BB}),std::vector<int>({1,4}));
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


   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Kamikaze,enum_Sensor::Eyes);
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);
   

   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Braindead,enum_Sensor::Eyes);
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+70,ecosysteme.getMilieu().getHeight()/2.0+2);
   b2->setOrientationDeg(180.0);

   

   //for ( int i = 1; i <= 20; ++i )
   //   ecosysteme.getMilieu().addMember( Bestiole() );
   ecosysteme.run();

   std::cout<<"End of program"<<std::endl;
   return 0;

}
