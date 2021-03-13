#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>
#include <string>     // std::string, std::stof

#include <map>
#include <random>
#include "Config.h"

using namespace std;





template<typename T>
T getRandomType(std::vector<T> types,std::vector<int> probs)
{
   std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> d(probs.begin(),probs.end());
    auto res=types[d(gen)];
    std::cout << res << '\n';
    return res;
}





enum MyEnum { AA=0 , BB=1  };

int main()
{
   for(int n=0; n<30; ++n)
      getRandomType<MyEnum>(std::vector<MyEnum>({AA,BB}),std::vector<int>({1,4}));

   const char* fname="config.txt";
   EnvConfig::ReadConfFile(fname);



   std::map<MyEnum, const char*> MyMap;
   //MyMap.insert(std::make_pair(AA, "Hi"));



   //Aquarium       ecosysteme( 640, 480, 30 );

   //for ( int i = 1; i <= 20; ++i )
   //   ecosysteme.getMilieu().addMember( Bestiole() );
   //ecosysteme.run();

   std::cout<<"End of program"<<std::endl;
   return 0;

}
