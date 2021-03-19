#include "Aquarium.h"

#include "Milieu.h"
#include "BestioleFactory.h"

Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{
   bool stillPressing=false;
   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() && !stillPressing) {
         stillPressing=true;
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();

         if(is_keySPACE())
         {
            cout<<"Pressed SPACE..."<<endl;
            BestioleFactory::createBestioleClone(*(flotte->getBestiolesList()[0]));
         }
         if(is_keyV())
         {
            cout<<"Pressed V..."<<endl;
            EnvConfig::sDrawSensors=!EnvConfig::sDrawSensors;
         }
      }
      else if(!is_key() )
      {
         stillPressing=false;
      }

      flotte->step();
      display( *flotte );

      wait( delay );

   } // while

}
