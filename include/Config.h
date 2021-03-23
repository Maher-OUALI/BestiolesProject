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
static bool sDebugCollsion;
static bool sDrawSensors;

static double sCloneProb;
static double sDieProb;
static double sBirthProb;

static double sTurboJetMod;
static double sShieldArmorMod;
static double sMinCloakStealthMod;
static double sMaxCloakStealthMod;


static double sPsychoChangeBProb;

static double sMaxVisionDist;
static double sMaxVisionAngle;
static double sMaxVisionIntensity;

static double sMaxHearingDist;
static double sMaxHearingIntensity;

static double sMinVisionDist;
static double sMinVisionAngle;
static double sMinVisionIntensity;

static double sMinHearingDist;
static double sMinHearingIntensity;

static int sMaxBestioles;
  
static int sMaxNeighborsPeureuse;
static double sRunawayFactorPeureuse;
static int sNbrStepsPrediction;


static double behaviourBrainDeadProb;
static double behaviourDumbProb;
static double behaviourGregaireProb;
static double behaviourKamikazeProb;
static double behaviourLazyProb;
static double behaviourPrevoyanteProb;
static double behaviourPsychoProb;
static double behaviourSpinnerProb;

static double sensorEyesProb;
static double sensorEarsProb;
static double sensorEyesEarsProb;

static double accesShieldPob;
static double accesCloakPob;
static double accesTurboJetPob;

static int sMaxtime;


static size_t ReadConfFile(const char* fname);





private:
static   size_t ReadVar(FILE* file,std::string &name,double &retval);

static void assignVar(const std::string name,const double value);


};

#endif

