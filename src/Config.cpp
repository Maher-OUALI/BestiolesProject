#include "Config.h"
#include <cstring>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>



double EnvConfig::sCollisionDieProb=0;
bool EnvConfig::sDebugVision=false;
bool EnvConfig::sDebugCollsion=false;
bool EnvConfig::sDrawSensors=true;

double EnvConfig::sBirthProb=0;
double EnvConfig::sCloneProb=0;
double EnvConfig::sDieProb=0;
double EnvConfig::sPsychoChangeBProb=0;

double EnvConfig::sTurboJetMod=0;
double EnvConfig::sShieldArmorMod=0;
double EnvConfig::sShieldSpeedMod=0.5;


double EnvConfig::sMinCloakStealthMod=0;
double EnvConfig::sMaxCloakStealthMod=0.9;

double EnvConfig::sMaxVisionDist=35;
double EnvConfig::sMaxVisionAngle=45;
double EnvConfig::sMaxVisionIntensity=0.8;

double EnvConfig::sMaxHearingDist=25;
double EnvConfig::sMaxHearingIntensity=0.6;

double EnvConfig::sMinVisionDist=35;
double EnvConfig::sMinVisionAngle=45;
double EnvConfig::sMinVisionIntensity=0.8;

double EnvConfig::sMinHearingDist=25;
double EnvConfig::sMinHearingIntensity=0.6;

int EnvConfig::sMaxBestioles=0;

int EnvConfig::sMaxNeighborsPeureuse=3;
double EnvConfig::sRunawayFactorPeureuse=3.0;
int EnvConfig::sNbrStepsPrediction=10;


double EnvConfig::behaviourBrainDeadProb=0;
double EnvConfig::behaviourDumbProb=0;
double EnvConfig::behaviourGregaireProb=0;
double EnvConfig::behaviourKamikazeProb=0;
double EnvConfig::behaviourLazyProb=0;
double EnvConfig::behaviourPrevoyanteProb=0;
double EnvConfig::behaviourPsychoProb=0;
double EnvConfig::behaviourSpinnerProb=0;

double EnvConfig::sensorEyesProb=0;
double EnvConfig::sensorEarsProb=0;
double EnvConfig::sensorEyesEarsProb=0;

double EnvConfig::accesShieldPob=0;
double EnvConfig::accesCloakPob=0;
double EnvConfig::accesTurboJetPob=0;
double EnvConfig::accesEmptyPob=0;

int EnvConfig::sMaxtime=0;
int EnvConfig::stepLogFreq=0;
int EnvConfig::sInitBestiolesNB=0;


std::string EnvConfig::experimentName="";


size_t EnvConfig::ReadConfFile(const char* fname)
{
   // FILE* ptr = fopen(fname,"r"); 
   //  if (ptr==NULL) 
   //  { 
   //      printf("No config file found."); 
   //      return 0; 
   //  } 

   //  printf("Config file found.....\n");
   // std::string var_name; 
   // double var_value;
   // while (!ReadVar(ptr,var_name,var_value))
   // {
   //    assignVar(var_name,var_value);
   // }
   // return 0;

   std::ifstream cFile (fname);
   if (cFile.is_open()){
      std::string line;
      //Get one line after another
      while(getline(cFile, line)){
        
            ProcessLine(line);

         
      } 


   }
}



size_t EnvConfig::ProcessLine(std::string & line)
   {
       std::vector<std::string> result; 
         std::istringstream iss(line); 
         //Split the line in words
         for(std::string s; iss >> s; ) 
            result.push_back(s); 


         if(result.size()==3)
         {
            //Check if we are defining the name
            if (result[0]=="NAME")
            {

               experimentName=result[2];
               std::cout<<"Name of experiment: "<<experimentName<<std::endl;
            }

            else
            {
               //Assign numeric values to global variables
               assignVar(result[0],std::stod (result[2]));
            }
         }
   }


//assign variables based on the read lines. Each if assigns a static variable that
// can be accesed across the program
void EnvConfig::assignVar(const std::string name,const double value)
{

   if (!strcmp(name.c_str(),"MAX_TIME"))
   {
      sMaxtime=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"STEP_LOG_FREQ"))
   {
      stepLogFreq=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"INIT_BESTIOLES_NB"))
   {
      sInitBestiolesNB=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"COLLISION_DIE_PROB"))
   {
      sCollisionDieProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"DEBUG_VISION"))
   {
      sDebugVision=(bool)value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"DEBUG_COLLISION"))
   {
      sDebugCollsion=(bool)value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"BIRTH_PROB"))
   {
      sBirthProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"CLONE_PROB"))
   {
      sCloneProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"DIE_PROB"))
   {
      sDieProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"PSYCH_CHANGEB_PROB"))
   {
      sPsychoChangeBProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }


   if (!strcmp(name.c_str(),"TURBO_JET_MOD"))
   {
      sTurboJetMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"SHIELD_ARMOR_MOD"))
   {
      sShieldArmorMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"SHIELD_SPEED_MOD"))
   {
      sShieldSpeedMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MIN_CLOAK_STEALTH_MOD"))
   {
      sMinCloakStealthMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MAX_CLOAK_STEALTH_MOD"))
   {
      sMaxCloakStealthMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }


   if (!strcmp(name.c_str(),"MIN_HEARING_INTENSITY"))
   {
      sMinHearingIntensity=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MIN_HEARING_DIST"))
   {
      sMinHearingDist=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MIN_VISION_INTENSITY"))
   {
      sMinVisionIntensity=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MIN_VISION_ANGLE"))
   {
      sMinVisionAngle=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MIN_VISION_DIST"))
   {
      sMinVisionDist=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

if (!strcmp(name.c_str(),"MAX_HEARING_INTENSITY"))
   {
      sMaxHearingIntensity=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MAX_HEARING_DIST"))
   {
      sMaxHearingDist=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MAX_VISION_INTENSITY"))
   {
      sMaxVisionIntensity=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MAX_VISION_ANGLE"))
   {
      sMaxVisionAngle=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MAX_VISION_DIST"))
   {
      sMaxVisionDist=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"MAX_BESTIOLES"))
   {
      sMaxBestioles=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   
   if (!strcmp(name.c_str(),"MAX_NEIGHBORS_PEUREUSE"))
   {
      sMaxNeighborsPeureuse=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   
   if (!strcmp(name.c_str(),"RUNAWAY_FACTOR_PEUREUSE"))
   {
      sRunawayFactorPeureuse=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }








   if (!strcmp(name.c_str(),"BEHAVIOUR_BRAINDEAD_PROB"))
   {
      behaviourBrainDeadProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"BEHAVIOUR_DUMB_PROB"))
   {
      behaviourDumbProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"BEHAVIOUR_SPINNER_PROB"))
   {
      behaviourSpinnerProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"BEHAVIOUR_GREGAIRE_PROB"))
   {
      behaviourGregaireProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"BEHAVIOUR_LAZY_PROB"))
   {
      behaviourLazyProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"BEHAVIOUR_PSYCHO_PROB"))
   {
      behaviourPsychoProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"BEHAVIOUR_KAMIKAZE_PROB"))
   {
      behaviourKamikazeProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"BEHAVIOUR_PREVOYANTE_PROB"))
   {
      behaviourPrevoyanteProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }





   if (!strcmp(name.c_str(),"SENSOR_EYES_PROB"))
   {
      sensorEyesProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }

   if (!strcmp(name.c_str(),"SENSOR_EARS_PROB"))
   {
      sensorEarsProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"SENSOR_EYESEARS_PROB"))
   {
      sensorEyesEarsProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }






   if (!strcmp(name.c_str(),"ACCES_CLOAK_PROB"))
   {
      accesCloakPob=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"ACCES_SHIELD_PROB"))
   {
      accesShieldPob=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"ACCES_TURBOJET_PROB"))
   {
      accesTurboJetPob=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   if (!strcmp(name.c_str(),"ACCES_EMPTY_PROB"))
   {
      accesEmptyPob=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   
   
   if (!strcmp(name.c_str(),"NBR_STEPS_PREDICTION"))
   {
      sNbrStepsPrediction=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
      return;
   }
   std::cout<<"variable"<<name<<"cannot be assigned"<<std::endl;
  
}
