#include "bestioleFactory.h"

#include "randomGen.h"

#include "spinnerBehaviour.h"
#include "dumbBehaviour.h"
#include "braindeadBehaviour.h"
#include "psychoBehaviour.h"
#include "eyes.h"
#include "ears.h"

#include <memory>


Milieu* BestioleFactory::milieu_=0;



std::shared_ptr<Bestiole> BestioleFactory::createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor,enum_Accesorie selected_accesorie)
{
    Behaviour* behav=createBehaviour( selected_behaviour);
    Sensor* sensor= createSensor(selected_sensor);
    Accesorie* accesorie= createAccesorie(selected_accesorie);
    std::shared_ptr<Bestiole> result =std::shared_ptr<Bestiole>( new Bestiole(sensor,behav,accesorie ));


    double init_x=static_cast<double>( rand() )/RAND_MAX*milieu_->getWidth();
    double init_y=static_cast<double>( rand() )/RAND_MAX*milieu_->getHeight();
    (*result).setCoords(init_x,init_y);
    milieu_->addMember(result);

    //ilan branch

    return result;
}


std::shared_ptr<Bestiole> BestioleFactory::createRandomBestiole()
{
    
    enum_Sensor curr_sensor=MyRandomGen::getRandomType<enum_Sensor>(vector<enum_Sensor>({enum_Sensor::Eyes,enum_Sensor::Ears,enum_Sensor::CompositeSensor}),vector<double>({0.3,0.3,0.3}));
    enum_Behavior curr_behaviour=MyRandomGen::getRandomType<enum_Behavior>(vector<enum_Behavior>({enum_Behavior::Dumb,enum_Behavior::Spinner}),vector<double>({0.5,0.5}));
    enum_Accesorie curr_accesorie=MyRandomGen::getRandomType<enum_Accesorie>(vector<enum_Accesorie>({enum_Accesorie::Turbojet}),vector<double>({1.0}));

    std::shared_ptr<Bestiole> result =createBestiole(curr_behaviour,curr_sensor,curr_accesorie);



    return result;
}

std::shared_ptr<Bestiole> BestioleFactory::createBestioleClone(const Bestiole & b)
{
    
    std::shared_ptr<Bestiole> result =std::shared_ptr<Bestiole>( new Bestiole(b ));
    milieu_->addMember(result);

    return result;
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


Accesorie* BestioleFactory::createAccesorie(enum_Accesorie selected_accesorie)
{

    Accesorie* acc;
    if(selected_accesorie==enum_Accesorie::Turbojet) acc= (Accesorie*)(new TurboJet()) ;

    return acc;
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
    else if (selected_sensor==enum_Sensor::CompositeSensor)
        {
            sensor= (Sensor*)(new CompositeSensor());
        }
    


    return sensor;
}
