#ifndef _RANDOMGEN_H_
#define _RANDOMGEN_H_


#include <random>

namespace MyRandomGen{


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

bool IsTrueRandom(double prob_true)
{
   std::random_device rd;
   std::mt19937 gen(rd());
   std::discrete_distribution<> d({1.0-prob_true,prob_true});
   return d(gen);
}

}

#endif