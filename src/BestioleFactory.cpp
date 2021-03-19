#include "BestioleFactory.h"
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
    if(selected_behaviour==enum_Behavior::Gregaire) beh= (Behaviour*)(new GregaireBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Kamikaze) beh= (Behaviour*)(new KamikazeBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Peureuse) beh= (Behaviour*)(new PeureuseBehaviour()) ;
    if(selected_behaviour==enum_Behavior::Prevoyante) beh= (Behaviour*)(new PrevoyanteBehaviour()) ;
    return beh;
}

Sensor* BestioleFactory::createSensor(enum_Sensor selected_sensor)
{

    Sensor* sensor;
    if(selected_sensor==enum_Sensor::Eyes) sensor= (Sensor*)(new Eyes()) ;
    if(selected_sensor==enum_Sensor::Ears) sensor= (Sensor*)(new Eyes()) ;
    if(selected_sensor==enum_Sensor::Composite) sensor= (Sensor*)(new CompositeSensor()) ;

    return sensor;
}
