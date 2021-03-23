#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>
#include <memory>


using namespace std;


class Milieu : public UImg
{

private :
   //static const T          white[];
   //static const T          black[];

   int                     width, height;
   std::vector<shared_ptr<Bestiole> >   listeBestioles;

public:
   int deathByCollisions;
   int naturalDeaths;
   int births;
   int clones;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( shared_ptr<Bestiole> b) { listeBestioles.push_back(b); listeBestioles.back(); }
   int nbVoisins( Bestiole* b);

   std::vector<shared_ptr<Bestiole> > & getBestiolesList()
   {
      return listeBestioles;
   }

   void applyDeath();

};

std::ostream& operator<<(std::ostream& os,  Milieu& b) ;



#endif
