#include "randomGen.h"



//Random boolean generator
bool MyRandomGen::IsTrueRandom(double prob_true)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::discrete_distribution<> d({1.0-prob_true,prob_true});
   return d(gen);
}

double MyRandomGen::RandomDouble(double b_min , double b_max)
{
   std::random_device rd;  //Will be used to obtain a seed for the random number engine
   std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
   std::uniform_real_distribution<> dis(b_min, b_max);

   return dis(gen);
}