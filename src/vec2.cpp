#include "vec2.h"


std::ostream& operator<<(std::ostream& os, const math::vector2& vec)
{
    os <<"(" <<vec[0] << ',' << vec[1] << ')' ;
    return os;
}


double math::constrainAngle(double x){
    x = fmod(x + 180,360);
    if (x < 0)
        x += 360;
    return x - 180;
}

double math::rad2Deg(double x){
    return(x *180.0/M_PI);
    
}

double math::deg2Rad(double x){
    return(x *M_PI/180.0);
    
}