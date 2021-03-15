#include "bestioleFactory.h"


Bestiole * BestioleFactory::createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor)
{
    Behaviour* behav=createBehaviour( selected_behaviour);
    Sensor* sensor= createSensor(selected_sensor);

    return new Bestiole(sensor,behav );
}

Behaviour* BestioleFactory::createBehaviour(enum_Behavior selected_behaviour)
{

    Behaviour* beh;
    if(selected_behaviour==enum_Behavior::Dumb) beh= (Behaviour*)(new DumbBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Spinner) beh= (Behaviour*)(new SpinnerBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Braindead) beh= (Behaviour*)(new BraindeadBehaviour()) ;
    return beh;
}

Sensor* BestioleFactory::createSensor(enum_Sensor selected_sensor)
{

    Sensor* sensor;
    if(selected_sensor==enum_Sensor::Eyes) sensor= (Sensor*)(new Eyes(0,0,0)) ;

    return sensor;
}
