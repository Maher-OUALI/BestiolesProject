#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include "Config.h"
#include "randomGen.h"


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


Bestiole::Bestiole(  Sensor* const sensor ,Behaviour* const behaviour )
{

   initState();

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   //x = y = 0;
   //cumulX = cumulY = 0.;
   pos=cumulPos=math::vector2();
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   //vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   base_vitesse = MAX_VITESSE;
   base_armour=1.0;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

   sensor_=sensor;
   sensor_->setOwner(this);
   behaviour_=behaviour;
   behaviour_->setOwner(this);

}


Bestiole::Bestiole( const Bestiole & b )
{

   initState();
   stillInCollsion=True; //we start at same position so collision will be obius.

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   //x = b.x;
   //y = b.y;
   pos=b.pos;


   //cumulX = cumulY = 0.;
   cumulPos=math::vector2();
   orientation = b.orientation+math::deg2Rad(90);

   //stats copy
   base_vitesse = b.base_vitesse;
   base_armour = b.base_armour;


   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

   sensor_=b.sensor_->clone(this);
   behaviour_=b.behaviour_->clone(this);

   sensor_->setOwner(this);
   behaviour_->setOwner(this);

}


// Bestiole::Bestiole(  Bestiole && b )
// {

//    initState();

//    identite = ++next;

//    cout << "const Bestiole (" << identite << ") par move" << endl;

//    //x = b.x;
//    //y = b.y;
//    pos=b.pos;


//    //cumulX = cumulY = 0.;
//    cumulPos=math::vector2();
//    orientation = b.orientation;
//    vitesse = b.vitesse;
//    couleur = new T[ 3 ];
//    memcpy( couleur, b.couleur, 3*sizeof(T) );

//    sensor_=b.sensor_;
//    sensor_->setOwner(this);
//    behaviour_=b.behaviour_;
//    behaviour_->setOwner(this);

// }


// Bestiole& Bestiole::operator=( Bestiole&& b)
// {
//    initState();

//    identite = ++next;

//    cout << "const Bestiole (" << identite << ") par move" << endl;

//    //x = b.x;
//    //y = b.y;
//    pos=b.pos;


//    //cumulX = cumulY = 0.;
//    cumulPos=math::vector2();
//    orientation = b.orientation;
//    vitesse = b.vitesse;
//    couleur = new T[ 3 ];
//    memcpy( couleur, b.couleur, 3*sizeof(T) );

//    sensor_=b.sensor_;
//    sensor_->setOwner(this);
//    behaviour_=b.behaviour_;
//    behaviour_->setOwner(this);

//    return *this;
// }


void Bestiole::initState()
{
   stillInCollsion=false;
   markedToDie=false;
}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   delete sensor_;
   delete behaviour_;

   cout << "Calling destructor on  "<<*this << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   //x = rand() % xLim;
   //y = rand() % yLim;
   pos=math::vector2(rand() % xLim,rand() % yLim);


}

void Bestiole::setCoords( double x, double y )
{

   //x = rand() % xLim;
   //y = rand() % yLim;
   pos=math::vector2(x,y);


}


void Bestiole::bouge( int xLim, int yLim )
{
   double final_speed=getFinalSpeed();
   double         nx, ny;
   double         dx = cos( orientation )*final_speed;
   double         dy = -sin( orientation )*final_speed;
   int            cx, cy;


   cx = static_cast<int>( cumulPos[0] ); cumulPos[0] -= cx;
   cy = static_cast<int>( cumulPos[1] ); cumulPos[1] -= cy;

   nx = pos[0] + dx + cx;
   ny = pos[1] + dy + cy;


   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulPos[0] = 0.;
   }
   else {
      pos[0] = static_cast<int>( nx );
      cumulPos[0] += nx - pos[0];
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulPos[1] = 0.;
   }
   else {
      pos[1] = static_cast<int>( ny );
      cumulPos[1] += ny - pos[1];
   }

}


void Bestiole::action( Milieu & monMilieu )
{
   checkCollisions(monMilieu);
   behaviour_->calculateDir(monMilieu);
   orientation=behaviour_->angle_rad;
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}

void Bestiole::setOrientationDeg(double angle)
{
   orientation=angle/180.0*M_PI;
}


void Bestiole::draw( UImg & support )
{

   //double         xt = pos[0] + cos( orientation )*AFF_SIZE/2.1;
   //double         yt = pos[1] - sin( orientation )*AFF_SIZE/2.1;
   math::vector2 relativePos=math::vector2().setCircle(AFF_SIZE/2.1,-orientation/M_PI*180.);
   relativePos=(pos+relativePos);


   support.draw_ellipse( pos[0], pos[1], AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( relativePos[0], relativePos[1], AFF_SIZE/2., couleur );

   DrawVisionCone(support,*this,orientation,relativePos);
   

}

void Bestiole::DrawVisionCone(UImg & support,const Bestiole & b,double orientation, math::vector2 relativePos)
{
   if(EnvConfig::sDrawSensors)
   {double triangleSIze=50.0;
   math::vector2 triangPoint1=math::vector2(1,1)*triangleSIze;
   math::vector2 triangPoint2=math::vector2(1,-1)*triangleSIze;
   
   triangPoint1=triangPoint1.rot(math::rad2Deg(-orientation))+relativePos;
   triangPoint2=triangPoint2.rot(math::rad2Deg(-orientation))+relativePos;
   support.draw_triangle(relativePos[0],relativePos[1],triangPoint1[0],triangPoint1[1],triangPoint2[0],triangPoint2[1],couleur,0.3);
}
}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

  
   return sensor_->canSense(b);

}


bool Bestiole::ocurredCollision(const Bestiole & b) 
{
   if (b.getIdentite() == identite)
      return false;

   double dist=math::vector2::distance(pos,b.getPosition());
   if(dist<2.5*AFF_SIZE )
      {
         
         if(!stillInCollsion) 
         {
         stillInCollsion=true;
         return true;
         }
         else
         return false;
      }
   stillInCollsion=false;
   return false;
}

void Bestiole::checkCollisions(Milieu & monMilieu )
{
   for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it )
      if ( ocurredCollision(**it) )
         {
            
            if(EnvConfig::sDebugCollsion) std::cout<<"EVENT:"<< *this <<" detected a collision with "<<(**it)<<endl;
            double prob = EnvConfig::sCollisionDieProb;
            if(MyRandomGen::IsTrueRandom(prob))
            {
               cout<<"EVENT: "<<*this<<" was marked to die"<<endl;
               markedToDie=true;
            }
         }
}


double Bestiole::getFinalSpeed()
{
   return base_vitesse*behaviour_->speed;
}
double Bestiole::getFinalArmor()
{
   return base_armour;
}








std::ostream& operator<<(std::ostream& os, const Bestiole& b)
{
    os <<"Bestiole_" <<b.getIdentite() ;
    return os;
}
