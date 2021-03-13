#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>
#include <string>     // std::string, std::stof

#include <map>
#include <random>
#include "Config.h"

#include "vec2.h"

using namespace std;




//Move
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





enum MyEnum { AA=0 , BB=1  };// Deleete

int main()
{
   //for(int n=0; n<30; ++n)
      //getRandomType<MyEnum>(std::vector<MyEnum>({AA,BB}),std::vector<int>({1,4}));

   math::vector2 vec1=math::vector2(0,1);
   math::vector2 vec2=math::vector2(1,1);

   std::cout<<vec1<<endl;
   std::cout<<vec2<<endl;
   std::cout<<vec1.deg()<<endl;
   std::cout<<math::vector2::angle(vec1,vec1)<<endl;


   const char* fname="config.txt";
   EnvConfig::ReadConfFile(fname);



   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i )
      ecosysteme.getMilieu().addMember( Bestiole() );
   ecosysteme.run();

   std::cout<<"End of program"<<std::endl;
   return 0;

}
