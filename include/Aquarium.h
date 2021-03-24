#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>
#include "Config.h"

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte;

   int            delay;

   int currentStep;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *flotte; }

   void run( void );

   int waitForKey();

   void saveState( fstream & MyFile );
   void saveBilan();

};


#endif
