#ifndef _CONFIG_H_
#define _CONFIG_H_


#include <iostream>
#include <string>     // std::string, std::stof

#include <map>
#include <random>

class EnvConfig
{


static double vcarlos;
static double vjorge;

public:

static size_t ReadConfFile(const char* fname);





private:
static   size_t ReadVar(FILE* file,std::string &name,double &retval);

static void assignVar(const std::string name,const double value);


};

#endif

