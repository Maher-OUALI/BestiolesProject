#include "Config.h"
#include <cstring>


double EnvConfig::vcarlos=0;
double EnvConfig::vjorge=0;
double EnvConfig::sCollisionDieProb=0;
bool EnvConfig::sDebugVision=false;
bool EnvConfig::sDebugCollision=false;
bool EnvConfig::sDrawSensors=false;




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
      sDebugCollision=(bool)value;
      printf("The global variable %s has value: %0.2f\n", name.c_str(),value); 
   }


  
  
}