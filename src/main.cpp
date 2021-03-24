#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"


#include <iostream>
#include <string>     // std::string, std::stof

#include <map>
#include "randomGen.h"
#include "Config.h"
#include "TestCases.h"

#include "vec2.h"



#include "BestioleFactory.h"

using namespace std;








template MyEnum MyRandomGen::getRandomType<MyEnum>(std::vector<MyEnum>,std::vector<double>);


int main(int argc, char** argv)
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


  char* fname="config.txt";

   

   if (argc >1)
   {
      fname=argv[1];
      cout<<"Reading: "<<argv[1]<<endl;
   }
   
   
   

   EnvConfig::ReadConfFile(fname);


   cout<< "=============================="<<endl;
   cout<< "0 : Normal0UnitTest"<<endl;
   cout<< "1 : kamikazeBehaviourUnitTest"<<endl;
   cout<< "2 : gregaireBehaviourUnitTest"<<endl;
   cout<< "3 : peureuseBehaviourUnitTest"<<endl;
   cout<< "4 : prevoyanteBehaviourUnitTest"<<endl;
   cout<< "5 : psychoBehaviourUnitTest"<<endl;
   cout<< "6 : earsSensorUnitTest"<<endl;
   cout<< "7 : eyesSensorUnitTest"<<endl;
   cout<< "8 : compositeSensorUnitTest"<<endl;
   cout<< "9 : cloakAccessoryUnitTest"<<endl;
   cout<< "10 : shieldAccessoryUnitTest"<<endl;
   cout<< "11 : turboJetAccessoryUnitTest"<<endl;
   cout<< "=============================="<<endl;
   cout<<"choose a test case number " << endl;

   int choice;
   cin >> choice;



   Aquarium       ecosysteme( 640, 640, 30 );
   BestioleFactory::milieu_=&ecosysteme.getMilieu();

   switch (choice) {
  case 0:
    TestCases::NormalUnitTest(ecosysteme);
    break;
  case 1:
    TestCases::kamikazeBehaviourUnitTest(ecosysteme);
    break;
  case 2:
    TestCases::gregaireBehaviourUnitTest(ecosysteme);
    break;
  case 3:
    TestCases::peureuseBehaviourUnitTest(ecosysteme);
    break;
  case 4:
    TestCases::prevoyanteBehaviourUnitTest(ecosysteme);
    break;
  case 5:
    TestCases::psychoBehaviourUnitTest(ecosysteme);
    break;
  case 6:
    TestCases::earsSensorUnitTest(ecosysteme);
    break;
  case 7:
    TestCases::eyesSensorUnitTest(ecosysteme);
    break;
   case 8:
    TestCases::compositeSensorUnitTest(ecosysteme);
    break;
   case 9:
    TestCases::cloakAccessoryUnitTest(ecosysteme);
    break;
   case 10:
    TestCases::shieldAccessoryUnitTest( ecosysteme);
    break;
   case 11:
    TestCases::turboJetAccessoryUnitTest(ecosysteme);
    break;
}
   
   /*
   for ( int i = 1; i <= 30; ++i )
       BestioleFactory::createRandomBestiole(); */
    ecosysteme.run();

   std::cout<<"End of program"<<std::endl;
   return 0;

}
