#include "Config.h"
#include <cstring>


double EnvConfig::vcarlos=0;
double EnvConfig::vjorge=0;
double EnvConfig::sCollisionDieProb=0;
bool EnvConfig::sDebugVision=false;
bool EnvConfig::sDebugCollsion=false;
bool EnvConfig::sDrawSensors=false;


double EnvConfig::sCloneProb=0;
double EnvConfig::sDieProb=0;
double EnvConfig::sPsychoChangeBProb=0;

double EnvConfig::sTurboJetMod=0;
double EnvConfig::sShieldArmorMod=0;
double EnvConfig::sCloakStealthMod=0;

double EnvConfig::sVisionDist=35;
double EnvConfig::sVisionAngle=45;
double EnvConfig::sVisionIntensity=0.8;

double EnvConfig::sHearingDist=25;
double EnvConfig::sHearingIntensity=0.6;

int EnvConfig::sMaxBestioles=0;



size_t EnvConfig::ReadConfFile(const char* fname)
{
   FILE* ptr = fopen(fname,"r"); 
    if (ptr==NULL) 
    { 
        printf("No config file found."); 
        return 0; 
    } 

    printf("Config file found.....\n");
   std::string var_name; 
   double var_value;
   while (!ReadVar(ptr,var_name,var_value))
   {
      assignVar(var_name,var_value);
   }
   return 0;
}



size_t EnvConfig::ReadVar(FILE* file,std::string &name,double &retval)
   {
      char var_name[100]; 
      char var_vstring[100]; 
      if (fscanf(file,"%s = %s\n",var_name,var_vstring)==2) 
      { 
         retval = std::stod (std::string(var_vstring));
         name=var_name;
         
         return 0;
      }
      return -1;
   }

void EnvConfig::assignVar(const std::string name,const double value)
{
   if (!strcmp(name.c_str(),"COLLISION_DIE_PROB"))
   {
      sCollisionDieProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"DEBUG_VISION"))
   {
      sDebugVision=(bool)value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"DEBUG_COLLISION"))
   {
      sDebugCollsion=(bool)value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }


   if (!strcmp(name.c_str(),"CLONE_PROB"))
   {
      sCloneProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"DIE_PROB"))
   {
      sDieProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"PSYCH_CHANGEB_PROB"))
   {
      sPsychoChangeBProb=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }


   if (!strcmp(name.c_str(),"TURBO_JET_MOD"))
   {
      sTurboJetMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"SHIELD_ARMOR_MOD"))
   {
      sShieldArmorMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"CLOAK_STEALTH_MOD"))
   {
      sCloakStealthMod=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }


   if (!strcmp(name.c_str(),"HEARING_INTENSITY"))
   {
      sHearingIntensity=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"HEARING_DIST"))
   {
      sHearingDist=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"VISION_INTENSITY"))
   {
      sVisionIntensity=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"VISION_ANGLE"))
   {
      sVisionAngle=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"VISION_DIST"))
   {
      sVisionDist=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }

   if (!strcmp(name.c_str(),"MAX_BESTIOLES"))
   {
      sMaxBestioles=value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }


  
}