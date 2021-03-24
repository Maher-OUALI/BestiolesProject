
#include "TestCases.h"

void TestCases::NormalUnitTest(Aquarium & ecosysteme){
   //simple start 
   for ( int i = 1; i <= EnvConfig::sInitBestiolesNB; ++i )
       BestioleFactory::createRandomBestiole(); 
}

void TestCases::kamikazeBehaviourUnitTest(Aquarium & ecosysteme){
    //force configuration
    EnvConfig::sCollisionDieProb=1.;
    //create a kamikaze bestiole
    Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Kamikaze,enum_Sensor::CompositeSensor,enum_Accessory::Empty).get();
    b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-200,ecosysteme.getMilieu().getHeight()/2.0);
    b1->setOrientationDeg(0.0);
    
    //create a Dumb bestiole
    Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes,enum_Accessory::Empty).get();
    b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+200,ecosysteme.getMilieu().getHeight()/2.0+50);
    b2->setOrientationDeg(180.0); 
}

void TestCases::gregaireBehaviourUnitTest(Aquarium & ecosysteme){
   
   //create a gregaire bestiole moving in one direction
   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Gregaire,enum_Sensor::CompositeSensor,enum_Accessory::Empty).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-200,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);
   
   //create two other bestiole moving the opposite direction
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes,enum_Accessory::Empty).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+200,ecosysteme.getMilieu().getHeight()/2.0+30);
   b2->setOrientationDeg(180.0);

   Bestiole* b3=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes,enum_Accessory::Empty).get();
   b3->setCoords(ecosysteme.getMilieu().getWidth()/2.0+200,ecosysteme.getMilieu().getHeight()/2.0-30);
   b3->setOrientationDeg(180.0);   
}

void TestCases::peureuseBehaviourUnitTest(Aquarium & ecosysteme){
   //force configuration
   EnvConfig::sCollisionDieProb=1.;
   //create a prevoyante bestiole
   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Peureuse,enum_Sensor::Ears,enum_Accessory::Empty).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-100,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);
   
   //create two other bestiole moving the opposite direction
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes,enum_Accessory::Empty).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+70,ecosysteme.getMilieu().getHeight()/2.0+10);
   b2->setOrientationDeg(180.0);

   Bestiole* b3=BestioleFactory::createBestiole(enum_Behavior::Spinner,enum_Sensor::Eyes,enum_Accessory::Empty).get();
   b3->setCoords(ecosysteme.getMilieu().getWidth()/2.0+70,ecosysteme.getMilieu().getHeight()/2.0-10);
   b3->setOrientationDeg(180.0);
}

void TestCases::prevoyanteBehaviourUnitTest(Aquarium & ecosysteme){
   //force configuration
   EnvConfig::sCollisionDieProb=1.;
   //create a prevoyante bestiole
   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Prevoyante,enum_Sensor::Ears,enum_Accessory::Empty).get();
   b1->setCoords(0.,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);
   
   //create two other bestiole moving the opposite direction
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes,enum_Accessory::Empty).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0,0.);
   b2->setOrientationDeg(90.0);
}

void TestCases::psychoBehaviourUnitTest(Aquarium & ecosysteme){
   //force configuration
   EnvConfig::sCollisionDieProb=1.;
   EnvConfig::sPsychoChangeBProb = 0.01;
   //create a psycho bestiole
   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Psycho,enum_Sensor::Ears,enum_Accessory::Empty).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-100,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);
   
   //create two other bestiole moving the opposite direction
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Spinner,enum_Sensor::Eyes,enum_Accessory::Empty).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+200,ecosysteme.getMilieu().getHeight()/2.0);
   b2->setOrientationDeg(180.0);
}

void TestCases::earsSensorUnitTest(Aquarium & ecosysteme){
   //force specific configuration
   EnvConfig::sCollisionDieProb=0.;
   EnvConfig::sDebugVision=true;
   EnvConfig::sMaxHearingDist=60;
   EnvConfig::sMinHearingDist=50;

   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Ears,enum_Accessory::Empty).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-100,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);

   //a tweak to not show hearing range
   EnvConfig::sMaxHearingDist=1;
   EnvConfig::sMinHearingDist=0;
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Spinner,enum_Sensor::Ears,enum_Accessory::Empty).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+200,ecosysteme.getMilieu().getHeight()/2.0);
   b2->setOrientationDeg(180.0);
   
}

void TestCases::eyesSensorUnitTest(Aquarium & ecosysteme){
   //force specific configuration
   EnvConfig::sCollisionDieProb=0.;
   EnvConfig::sDebugVision=true;

   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::Eyes,enum_Accessory::Empty).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-100,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);

   //a tweak to not show hearing range
   EnvConfig::sMaxHearingDist=1;
   EnvConfig::sMinHearingDist=0;
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Spinner,enum_Sensor::Ears,enum_Accessory::Empty).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+200,ecosysteme.getMilieu().getHeight()/2.0);
   b2->setOrientationDeg(180.0);
}

void TestCases::compositeSensorUnitTest(Aquarium & ecosysteme){
   //force specific configuration
   EnvConfig::sCollisionDieProb=0.;
   EnvConfig::sDebugVision=true;
   EnvConfig::sMaxVisionDist=70;
   EnvConfig::sMinVisionDist=60;
   EnvConfig::sMaxHearingDist=50;
   EnvConfig::sMinHearingDist=40;

   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Dumb,enum_Sensor::CompositeSensor,enum_Accessory::Empty).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-100,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);

   //a tweak to not show hearing range
   EnvConfig::sMaxHearingDist=1;
   EnvConfig::sMinHearingDist=0;
   Bestiole* b2=BestioleFactory::createBestiole(enum_Behavior::Spinner,enum_Sensor::Ears,enum_Accessory::Empty).get();
   b2->setCoords(ecosysteme.getMilieu().getWidth()/2.0+200,ecosysteme.getMilieu().getHeight()/2.0);
   b2->setOrientationDeg(180.0);
}

void TestCases::cloakAccessoryUnitTest(Aquarium & ecosysteme){

}

void TestCases::shieldAccessoryUnitTest(Aquarium & ecosysteme){

}

void TestCases::turboJetAccessoryUnitTest(Aquarium & ecosysteme){

}

void TestCases::Debugtest(Aquarium & ecosysteme){

    //create a gregaire bestiole moving in one direction
   Bestiole* b1=BestioleFactory::createBestiole(enum_Behavior::Gregaire,enum_Sensor::CompositeSensor,enum_Accessory::Empty).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0-200,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(0.0);

   Bestiole* b2=BestioleFactory::createBestioleClone(*b1).get();
   b1->setCoords(ecosysteme.getMilieu().getWidth()/2.0,ecosysteme.getMilieu().getHeight()/2.0);
   b1->setOrientationDeg(180.0);

   



}
