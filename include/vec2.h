#ifndef __VECTOR2_H__
#define __VECTOR2_H__

/******************************************************************************
 *
 * Author      : Mario Konrad, Mario.Konrad@gmx.net
 *
 * Copyright (C) Mario Konrad
 *
 ******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 ******************************************************************************/

#include <cmath>
#include <iostream>
#include <string> 

namespace math {

class vector2
{
	public:
		enum AXIS { X = 0, Y };

		enum ANGLE { PHI = 0 };

		vector2(double x = 0.0, double y = 0.0)
		{ this->x[0]=x; this->x[1]=y; }

		vector2(const vector2 & v)
		{ *this = v; }

		vector2(double * v)
		{ x[0]=v[0]; x[1]=v[1]; }

		inline vector2 & set(double a, double b)
		{ x[0]=a; x[1]=b; return *this; }

		inline vector2 & setCircle(double r, double phi_deg)
		{
			phi_deg *= (M_PI / 180.0);
			x[0] = r * cos(phi_deg);
			x[1] = r * sin(phi_deg);
			return *this;
		}

		inline double dot(const vector2 & v) const
		{ return x[0]*v.x[0] + x[1]*v.x[1]; }

		inline double length() const
		{ return sqrt(length2()); }

		inline double length2() const
		{ return x[0]*x[0] + x[1]*x[1]; }

		inline vector2 & normalize(double len = 1.0)
		{
			double l = length();
			return (l != 0.0) ? (*this *= (len / l)) : (*this);
		}

		inline vector2 & rot(double angle_deg)
		{
			angle_deg *= M_PI / 180.0;
			double c = cos(angle_deg);
			double s = sin(angle_deg);
			return *this = vector2(x[0] * c - x[1] * s, x[0] * s + x[1] * c);
		}

		

		inline double operator [] (int idx) const
		{ return x[idx]; }

		inline double & operator [] (int idx)
		{ return x[idx]; }

		inline operator const double * (void) const
		{ return x; }

		inline vector2 & operator = (const vector2 & v)
		{ x[0]=v.x[0]; x[1]=v.x[1]; return *this; }

		inline bool operator == (const vector2 & v)
		{ return ((x[0]==v.x[0]) && (x[1]==v.x[1])); }

		inline vector2 & operator += (const vector2 & v)
		{ x[0]+=v.x[0]; x[1]+=v.x[1]; return *this; }

		inline vector2 & operator -= (const vector2 & v)
		{ x[0]-=v.x[0]; x[1]-=v.x[1]; return *this; }

		inline vector2 & operator *= (double f)
		{ x[0]*=f; x[1]*=f; return *this; }

		friend vector2 operator + (const vector2 & w, const vector2 & v)
		{ return vector2(w) += v; }

		friend vector2 operator - (const vector2 & w, const vector2 & v)
		{ return vector2(w) -= v; }

		friend vector2 operator * (const vector2 & v, double f)
		{ return vector2(v) *= f; }

		friend vector2 operator * (double f, const vector2 & v)
		{ return vector2(v) *= f; }

		friend double operator * (const vector2 & a, const vector2 & b)
		{ return a.dot(b); }

		double angleDeg ()
		{ return std::atan2(x[1], x[0])* (180.0/M_PI);}


		static double angleBetween(const vector2 v1,const vector2 v2)
		{
			
			double vector_dot, mult_abs;
			mult_abs =   v1.length()*v2.length();
			vector_dot=v1.dot(v2);
			return acos(vector_dot/mult_abs)* (180.0/M_PI);
		}

		static double distance(const vector2 v1,const vector2 v2)
		{
			
			return (v2-v1).length();
		}

		//friend std::ostream& operator<<(std::ostream& os, const math::vector2& vec);


	private:
		double x[2];
};

double constrainAngle(double x);

double rad2Deg(double x);

double deg2Rad(double x);

}

std::ostream& operator<<(std::ostream& os, const math::vector2& vec);



#endif