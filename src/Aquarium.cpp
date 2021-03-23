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

            saveBilan();
           




            close();
         }

         if(is_keySPACE())
         {
            cout<<"Pressed SPACE..."<<endl;
            BestioleFactory::createRandomBestiole();;
         }
         if(is_keyV())
         {
            cout<<"Pressed V..."<<endl;
            EnvConfig::sDrawSensors=!EnvConfig::sDrawSensors;
         }
         if(is_keyS())
         {
            cout<<"Pressed S..."<<endl;
            flotte->getBestiolesList()[0]->changeBehaviour(BestioleFactory::createRandomBehaviour());
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


void Aquarium::saveBilan( )
{
   std::stringstream namef; 
   map<string,int> sums;
   sums["Eyes"]=0;
   sums["EyesEars"]=0;
   sums["Ears"]=0;

   sums["TurboJet"]=0;
   sums["Shield"]=0;
   sums["Cloak"]=0;

   sums["BrainDead"]=0;
   sums["Dumb"]=0;
   sums["Spinner"]=0;
   sums["Lazy"]=0;
   sums["Kamikaze"]=0;
   sums["Greagaire"]=0;
   sums["Psycho"]=0;
     for ( std::vector<shared_ptr<Bestiole> >::iterator it = flotte->getBestiolesList().begin() ; it != flotte->getBestiolesList().end() ; ++it )
            {
               sums[(*it)->getSensor()->getName()]+=1;
               sums[(*it)->getBehaviour()->getName()]+=1;
               sums[(*it)->getAccessory()->getName()]+=1;
            }
            namef.str("");
            namef<<"./results/bilan.csv"; 
            cout<<"Writting to :"<<namef.str()<<endl;
            fstream MyFile;
            MyFile.open(namef.str(),std::ios::out);
            //MyFile << fflush;
            for( auto iter = sums.begin(); iter != sums.end(); iter++ ) {
               MyFile << "component: " << iter->first << ", quantity: " << iter->second << endl;
            }
            //MyFile<<"Hi";
            MyFile.close();
}