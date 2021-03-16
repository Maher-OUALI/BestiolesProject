#include "randomGen.h"



// template<typename T>
// T MyRandomGen::getRandomType(std::vector<T> types,std::vector<double> probs)
//     {
//     std::random_device rd;
//         std::mt19937 gen(rd());
//         std::discrete_distribution<> d(probs.begin(),probs.end());
//         auto res=types[d(gen)];
//         std::cout << res << std::endl;
//         return res;
//     }



bool MyRandomGen::IsTrueRandom(double prob_true)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::discrete_distribution<> d({1.0-prob_true,prob_true});
   return d(gen);
}

//template MyEnum MyRandomGen::getRandomType<MyEnum>(std::vector<MyEnum>,std::vector<double>);
//template PsycBehvrs MyRandomGen::getRandomType<PsycBehvrs>(std::vector<PsycBehvrs>,std::vector<double>);