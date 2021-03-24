#include "BestioleFactory.h"

#include "randomGen.h"

//include behaviours
#include "SpinnerBehaviour.h"
#include "DumbBehaviour.h"
#include "BraindeadBehaviour.h"
#include "PsychoBehaviour.h"
#include "GregaireBehaviour.h"
#include "PrevoyanteBehaviour.h"
#include "PeureuseBehaviour.h"
#include "KamikazeBehaviour.h"

//include sensors
#include "CompositeSensor.h"
#include "Eyes.h"
#include "Ears.h"

//include Accessories
#include "TurboJet.h"
#include "Shield.h"
#include "Cloak.h"
#include "Empty.h"

#include <memory>


Milieu* BestioleFactory::milieu_=0;



std::shared_ptr<Bestiole> BestioleFactory::createBestiole(enum_Behavior selected_behaviour,enum_Sensor selected_sensor,enum_Accessory selected_accessory)
{
    if ((int)(milieu_->getBestiolesList().size())<EnvConfig::sMaxBestioles)
    {

        //Create components
        Behaviour* behav=createBehaviour( selected_behaviour);
    Sensor* sensor= createSensor(selected_sensor);
    Accessory* accessory= createAccessory(selected_accessory);

    //Final bestiole
    std::shared_ptr<Bestiole> result =std::shared_ptr<Bestiole>( new Bestiole(sensor,behav,accessory ));


    double init_x=static_cast<double>( rand() )/RAND_MAX*milieu_->getWidth();
    double init_y=static_cast<double>( rand() )/RAND_MAX*milieu_->getHeight();
    (*result).setCoords(init_x,init_y);

    //Register to milieu 
    milieu_->addMember(result);


    return result;
    }
    else{
        return nullptr;
    }
}


std::shared_ptr<Bestiole> BestioleFactory::createRandomBestiole()
{
    //random sensor type generation
    enum_Sensor curr_sensor=MyRandomGen::getRandomType<enum_Sensor>(vector<enum_Sensor>(
        {enum_Sensor::Eyes,
        enum_Sensor::Ears,
        enum_Sensor::CompositeSensor}),
        vector<double>(
            {EnvConfig::sensorEyesProb,
            EnvConfig::sensorEarsProb,
            EnvConfig::sensorEyesEarsProb}
            ));
 //random behaviour type generation

    enum_Behavior curr_behaviour=MyRandomGen::getRandomType<enum_Behavior>(vector<enum_Behavior>(
        {enum_Behavior::Dumb,
        enum_Behavior::Braindead,
        enum_Behavior::Gregaire,
        enum_Behavior::Kamikaze,
        enum_Behavior::Peureuse,
        enum_Behavior::Prevoyante,
        enum_Behavior::Spinner,
        enum_Behavior::Psycho}),vector<double>(
            {EnvConfig::behaviourDumbProb,
            EnvConfig::behaviourBrainDeadProb,
            EnvConfig::behaviourGregaireProb,
            EnvConfig::behaviourKamikazeProb,
            EnvConfig::behaviourLazyProb,
            EnvConfig::behaviourPrevoyanteProb,
            EnvConfig::behaviourSpinnerProb,
            EnvConfig::behaviourPsychoProb}
            ));

 //random accesory type generation
    enum_Accessory curr_accessory=MyRandomGen::getRandomType<enum_Accessory>(vector<enum_Accessory>(
        {enum_Accessory::Turbojet,enum_Accessory::Shield,enum_Accessory::Cloak,enum_Accessory::Empty}),
        vector<double>(
            {EnvConfig::accesTurboJetPob,
            EnvConfig::accesShieldPob,
            EnvConfig::accesCloakPob,
            EnvConfig::accesEmptyPob}));

    std::shared_ptr<Bestiole> result =createBestiole(curr_behaviour,curr_sensor,curr_accessory);



    return result;
}
//Cloning methods
std::shared_ptr<Bestiole> BestioleFactory::createBestioleClone( Bestiole & b)
{

    if ((int)(milieu_->getBestiolesList().size())<EnvConfig::sMaxBestioles)
    {
    b.stillInCollsion=True;
    std::shared_ptr<Bestiole> result =std::shared_ptr<Bestiole>( new Bestiole(b ));
    b.lastCollWith=result->getIdentite();
    milieu_->addMember(result);
    //Notify events for results generation in csv
    milieu_->clones+=1;
    return result;
    }
    return nullptr;
    
}


Behaviour* BestioleFactory::createRandomBehaviour()
{
    //Get random type of behaviour
    enum_Behavior curr_behaviour=MyRandomGen::getRandomType<enum_Behavior>(vector<enum_Behavior>(
        {enum_Behavior::Dumb,
        enum_Behavior::Braindead,
        enum_Behavior::Gregaire,
        enum_Behavior::Kamikaze,
        enum_Behavior::Peureuse,
        enum_Behavior::Prevoyante,
        enum_Behavior::Spinner,
        enum_Behavior::Psycho}),vector<double>(
            {EnvConfig::behaviourDumbProb,
            EnvConfig::behaviourBrainDeadProb,
            EnvConfig::behaviourGregaireProb,
            EnvConfig::behaviourKamikazeProb,
            EnvConfig::behaviourLazyProb,
            EnvConfig::behaviourPrevoyanteProb,
            EnvConfig::behaviourSpinnerProb,
            EnvConfig::behaviourPsychoProb}
            ));
    Behaviour* behav=createBehaviour( curr_behaviour);
    cout<<"New random behaviour: "<<behav->getName()<<endl;
    return behav;

}
//////////Creation functions from enum types


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
    if(selected_behaviour==enum_Behavior::Psycho) beh= (Behaviour*)(new PsychoBehaviour()) ;
    return beh;
}


Accessory* BestioleFactory::createAccessory(enum_Accessory selected_accessory)
{

    Accessory* acc;
    if(selected_accessory==enum_Accessory::Turbojet) acc= (Accessory*)(new TurboJet()) ;
    if(selected_accessory==enum_Accessory::Shield) acc= (Accessory*)(new Shield()) ;
    if(selected_accessory==enum_Accessory::Cloak) acc= (Accessory*)(new Cloak()) ;
    if(selected_accessory==enum_Accessory::Empty) acc= (Accessory*)(new Empty()) ;

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
