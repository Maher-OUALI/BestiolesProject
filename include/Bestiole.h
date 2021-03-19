#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include "vec2.h"
#include "Sensor.h"
#include "Behaviour.h"

using namespace std;



enum  class enum_Behavior
{
   Dumb,
   Spinner,
   Braindead
};

enum  class enum_Sensor
{
   Eyes
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

   T               * couleur;

   bool stillInCollsion;

   Sensor* sensor_;
   Behaviour* behaviour_;



public:
   bool markedToDie;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole(   Sensor* const sensor ,Behaviour* const behaviour);                               // Constructeur par defaut
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

   math::vector2 getPosition()const {return pos;}
   double getAngleDeg(){return orientation/M_PI*180;}
   T* getColeur(){return couleur;}


   void initState();

   Sensor* getSensor(){return sensor_;}

   bool ocurredCollision(const Bestiole & b) ;

   void checkCollisions(Milieu & monMilieu );

   int getIdentite() const {return identite;}

   double getFinalSpeed();
   double getFinalArmor();


   //Temporary
   void DrawVisionCone(UImg & support,const Bestiole & b,double orientation, math::vector2 relativePos);

};

std::ostream& operator<<(std::ostream& os, const Bestiole& b);


#endif
