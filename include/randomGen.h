#ifndef _RANDOMGEN_H_
#define _RANDOMGEN_H_
#include <iostream>

#include <random>

enum  MyEnum { AA , BB  };// Deleete


namespace MyRandomGen{




bool IsTrueRandom(double prob_true);
template<typename T>
T getRandomType(std::vector<T> types,std::vector<double> probs)
    {
    std::random_device rd;
        std::mt19937 gen(rd());
        std::discrete_distribution<> d(probs.begin(),probs.end());
        auto res=types[d(gen)];
        //std::cout << res << std::endl;
        return res;
    }


}

//template<typename T>
//extern  T MyRandomGen::getRandomType(std::vector<T> types,std::vector<double> probs);
// template<typename T>
// class TypeRandomGenerator
// {
    
//     public:
//     static 

// };



#endif