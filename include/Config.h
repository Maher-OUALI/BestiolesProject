#ifndef _CONFIG_H_
#define _CONFIG_H_


#include <iostream>
#include <string>     // std::string, std::stof

#include <map>
#include <random>

class EnvConfig
{




public:
static double vcarlos;
static double vjorge;
static double sCollisionDieProb;
static bool sDebugVision;
static bool sDebugCollision;
static bool sDrawSensors;

static double sCloneProb;
static double sDieProb;

static double sTurboJetMod;


static double sPsychoChangeBProb;

static double sVisionDist;
static double sVisionAngle;
static double sVisionIntensity;

static double sHearingDist;
static double sHearingIntensity;

static int sPeureseMaxNeighbors;
static double sPeureuseSpeedFactor;


static size_t ReadConfFile(const char* fname);





private:
static   size_t ReadVar(FILE* file,std::string &name,double &retval);

static void assignVar(const std::string name,const double value);


};

#endif

