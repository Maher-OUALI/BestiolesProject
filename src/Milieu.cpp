#include "Milieu.h"

#include <cstdlib>
#include <ctime>

#include <cmath>
#include "colors.h"


// const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
// const T    Milieu::black[] = { (T)0, (T)0, (T)0 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, Colors::white[0], Colors::white[1], Colors::white[2] );
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      (*it)->action( *this );
      (*it)->draw( *this );

      
      //draw_circle( width/2, height/2, 40., Colors::black );

   } // for

   applyDeath();

}


int Milieu::nbVoisins( Bestiole const * b )
{

   int         nb = 0;


   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == (*it)) && b->jeTeVois(**it) )
         ++nb;

   return nb;

}

bool shouldDie(Bestiole *b)
{
   return b->markedToDie;
}

void Milieu::applyDeath()
{
   listeBestioles.erase(std::remove_if(listeBestioles.begin(), listeBestioles.end(), shouldDie), listeBestioles.end());
}
