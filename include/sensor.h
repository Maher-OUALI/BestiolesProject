#ifndef _SENSOR_H_
#define _SENSOR_H_




class Bestiole;

class Sensor
{
protected:
    Bestiole* owner;
    double angle;
    double distance;
    double detectionCapacity;

    
public:
    Sensor()
    {
        
    }
    virtual bool canSense(const Bestiole &b2)=0;

    virtual Sensor* clone(Bestiole* ownr);

    void setOwner(Bestiole* ownr){owner= ownr;}

    virtual ~Sensor();


};


#endif