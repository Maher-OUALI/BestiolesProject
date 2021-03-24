#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include "vec2.h"
#include "Sensor.h"
#include "Behaviour.h"
#include  "Accessory.h"

using namespace std;



enum  class enum_Behavior
{
   Dumb,
   Spinner,
   Braindead, 
   Gregaire, 
   Kamikaze,
   Peureuse,
   Prevoyante,
   Psycho
};

enum  class enum_Sensor
{
   Eyes,
   Ears,
   CompositeSensor
};

enum  class enum_Accessory
{
   Turbojet,
   Cloak,
   Shield
};






class Milieu;


class Bestiole
{


private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;


   static int              next;

   

private :
   int               identite;
   //int               x, y;
   //double            cumulX, cumulY;
   math::vector2 pos;
   math::vector2 cumulPos;

   double            orientation;

   //Base stats
   double            base_vitesse;
   double            base_armour;
   double            base_stealth;

   T               * couleur;

   

   Sensor* sensor_;
   Behaviour* behaviour_;
   Accessory* accessory_;




public:
   bool markedToDie;
   bool markedToClone;
   bool stillInCollsion;

   int lastCollWith;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole(   Sensor* const sensor ,Behaviour* const behaviour,Accessory* const accessory);                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   //Bestiole( Bestiole && b );                 // Move constructor
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );
   void setCoords( double x, double y );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   //Bestiole& operator=( Bestiole&& b);

   void setOrientationDeg(double angle);
   double getOrientationRad(){return orientation;}
   double getAFF_SIZE(){return AFF_SIZE;}

   math::vector2 getPosition()const {return pos;}
   double getAngleDeg(){return orientation/M_PI*180;}
   T* getColeur(){return couleur;}


   void initState();

   Sensor* getSensor(){return sensor_;}
   Behaviour* getBehaviour(){return behaviour_;}
    Accessory* getAccessory(){return accessory_;}

   bool ocurredCollision(const Bestiole & b) ;

   void checkCollisions(Milieu & monMilieu );

   int getIdentite() const {return identite;}

   double getFinalSpeed();
   double getFinalArmor();
   double getFinalStealth() const;


   void changeBehaviour(Behaviour* newBehaviour)
   {
      if(behaviour_!=nullptr)
         delete behaviour_;
      behaviour_=newBehaviour;
      behaviour_->setOwner(this);
      
   }


   //Temporary
   void DrawVisionCone(UImg & support,const Bestiole & b,double orientation, math::vector2 relativePos);

   // std::ostream&  printInfo(std::ostream& os){
   //    os<<identite<<" , "<<behaviour_->getName()<<" , "<<sensor_->getName()<<" , "<<accessory_->getName()<<endl;
   //    return os;
   // }

};

std::ostream& operator<<(std::ostream& os, const Bestiole& b);



#endif
