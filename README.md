# BestiolesProject
c++ project for UE Advanced C++ Programming

Launching:
1) Open a terminal
2) run .\/build/main

Configuration:
The config file config.txt probides parameters to tweak before starting the simulation.

COLLISION_DIE_PROB  :  The probability to die from a collsion
DEBUG_VISION. :  Print in terminal if a bestiole can see another one
DEBUG_COLLISION  : Print in terminal if a bestiole collided another one
CLONE_PROB. : probability that a bestiole gets cloned
DIE_PROB  : Probability of sudden death of a bestiole
PSYCH_CHANGEB_PROB  :  probability that the psycho behaviour changes behaviour
TURBO_JET_MOD : How much the the accesorie changes speed
SHIELD_ARMOR_MOD  : How much the the accesorie changes armor

MIN_CLOAK_STEALTH_MOD  : How much the the accesorie changes stealth
MAX_CLOAK_STEALTH_MOD  : How much the the accesorie changes stealth

#sensor parameters

MIN_VISION_DIST = 100

MIN_VISION_ANGLE = 45

MIN_VISION_INTENSITY = 0.9

MIN_HEARING_DIST = 30

MIN_HEARING_INTENSITY = 0.7

MAX_VISION_DIST = 100

MAX_VISION_ANGLE = 45

MAX_VISION_INTENSITY = 0.9

MAX_HEARING_DIST = 30

MAX_HEARING_INTENSITY = 0.7

MAX_BESTIOLES Maximum bestioles allowed during simulation

#Behaviour parameters

MAX_NEIGHBORS_PEUREUSE = 0

RUNAWAY_FACTOR_PEUREUSE = 3.0




#Probabilities of instantiation during creation of bestiole

BEHAVIOUR_BRAINDEAD_PROB = 0.0

BEHAVIOUR_DUMB_PROB = 0.0

BEHAVIOUR_SPINNER_PROB = 0.1

BEHAVIOUR_GREGAIRE_PROB = 0.0

BEHAVIOUR_LAZY_PROB = 0.0

BEHAVIOUR_KAMIKAZE_PROB = 0.0

BEHAVIOUR_PREVOYANTE_PROB = 0.0



SENSOR_EYES_PROB = 0.1

SENSOR_EARS_PROB = 0.0

SENSOR_EYESEARS_PROB = 0.0


ACCES_CLOAK_PROB = 0.1

ACCES_TURBOJET_PROB = 0.1

ACCES_SHIELD_PROB = 0.1

Usage:
Keyboard keys can be used as followed
-Key P: save a snapshot of the state in csv format at the folder /results
-Key Space: spawn a clone of the first bestiole
-Key V: visualize sensors detection region for each bestiole
