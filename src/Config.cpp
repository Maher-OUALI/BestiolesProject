#include "Config.h"
#include <cstring>


double EnvConfig::vcarlos=0;
double EnvConfig::vjorge=0;




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
         printf("The global variable %s has value: %0.2f\n", var_name,retval); 
         return 0;
      }
      return -1;
   }

void EnvConfig::assignVar(const std::string name,const double value)
{
   if (!strcmp(name.c_str(),"Pepe"))
   {
      vcarlos=value;
   }

   if (!strcmp(name.c_str(),"Jorge"))
   {
      vjorge=value;
   }
  
  
}