#include "Aquarium.h"

#include "Milieu.h"
#include "BestioleFactory.h"

#include <fstream>
#include <iostream>
#include <sstream>

Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();

   currentTime=0;


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
   std::stringstream namef; 
   system("rm ./results/* ");
   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() && !stillPressing) {
         stillPressing=true;
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) {
            saveState(namef);
            close();
         }

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
         if(is_keyP())
         {
            cout<<"Pressed P..."<<endl;
            cout<<"Current time: "<<currentTime<<endl;
            cout<<getMilieu();

            saveState(namef);
     
         }
      }
      else if(!is_key() )
      {
         stillPressing=false;
      }

      flotte->step();
      display( *flotte );

      wait( delay );

      currentTime+=delay;

   } // while

}


void Aquarium::saveState( stringstream & namef )
{
   namef.str("");
   namef<<"./results/"<<currentTime<<".csv"; 
   cout<<"Writting to :"<<namef.str()<<endl;
   fstream MyFile;
   MyFile.open(namef.str(),std::ios::out);
   MyFile << fflush;
   MyFile<<getMilieu();
   MyFile.close();
}
