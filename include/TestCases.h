#ifndef _TESTCASES_H_
#define _TESTCASES_H_


#include "Aquarium.h"
#include "BestioleFactory.h"
#include "Bestiole.h"
#include "Config.h"

namespace TestCases
{
void NormalUnitTest(Aquarium & ecosystem);
void kamikazeBehaviourUnitTest(Aquarium & ecosystem);
void gregaireBehaviourUnitTest(Aquarium & ecosystem);
void prevoyanteBehaviourUnitTest(Aquarium & ecosystem);
void peureuseBehaviourUnitTest(Aquarium & ecosystem);
void psychoBehaviourUnitTest(Aquarium & ecosystem);

void earsSensorUnitTest(Aquarium & ecosystem);
void eyesSensorUnitTest(Aquarium & ecosystem);
void compositeSensorUnitTest(Aquarium & ecosystem);

void cloakAccessoryUnitTest(Aquarium & ecosystem);
void shieldAccessoryUnitTest(Aquarium & ecosystem);
void turboJetAccessoryUnitTest(Aquarium & ecosystem);
void Debugtest(Aquarium & ecosystem);

}

#endif
