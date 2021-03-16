#include "bestioleFactory.h"

#include "spinnerBehaviour.h"
#include "dumbBehaviour.h"
#include "braindeadBehaviour.h"
#include "psychoBehaviour.h"
#include "eyes.h"
#include "ears.h"

#include <memory>


Milieu* BestioleFactory::milieu_=0;



Bestiole*BestioleFactory::createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor)
{
    Behaviour* behav=createBehaviour( selected_behaviour);
    Sensor* sensor= createSensor(selected_sensor);
    std::shared_ptr<Bestiole> result =std::shared_ptr<Bestiole>( new Bestiole(sensor,behav ));
    milieu_->addMember(result);

    //ilan branch

    return result.get();
}

Bestiole* BestioleFactory::createBestioleClone(const Bestiole & b)
{
    
    std::shared_ptr<Bestiole> result =std::shared_ptr<Bestiole>( new Bestiole(b ));
    milieu_->addMember(result);

    return result.get();
}

Behaviour* BestioleFactory::createBehaviour(enum_Behavior selected_behaviour)
{

    Behaviour* beh;
    if(selected_behaviour==enum_Behavior::Dumb) beh= (Behaviour*)(new DumbBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Spinner) beh= (Behaviour*)(new SpinnerBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Braindead) beh= (Behaviour*)(new BraindeadBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Psycho) beh= (Behaviour*)(new PsychoBehaviour()) ;
    return beh;
}

Sensor* BestioleFactory::createSensor(enum_Sensor selected_sensor)
{

    Sensor* sensor;
    if(selected_sensor==enum_Sensor::Eyes) 
        {
            sensor= (Sensor*)(new Eyes());
        }
    else if (selected_sensor==enum_Sensor::Ears)
        {
            sensor= (Sensor*)(new Ears());
        }


    return sensor;
}
