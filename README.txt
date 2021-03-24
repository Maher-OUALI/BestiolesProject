Launching:
1) Open a terminal
2) Build using command make (make clean for starting again)
2) run .\/build/main 
or
 .\/build/main [Directory to custom config file:DEFAULT=config.txt]


Some .txt experiments are provided:
1) onlykamikaze.txt
2) highbirths.txt
3) higharmature.txt
4) balanced.txt

///////////////////////////////////////////////////////////////////////////////////////
Color Guidelines

Behaviours
Gregaire: Green
Kamikaze: Red
Peureseuse: Dark Yellow
Prevoyante: Blue
Psycho: Color of current active behaviour

Accessories
Cloak: Pink
Shield: Brown
TurboJet: Cyan

Sensors
Can be seen by pressing the key "V"

///////////////////////////////////////////////////////////////////////////////////////
Configuration:
The config file config.txt provides parameters to tweak before starting the simulation.

NAME is the name of the experiment, this allows to save csv with specific names.

MAX_TIME Maximum time of simulation (0 for unlimited)
STEP_LOG_FREQ Frequency of state logging (0 for disabled)
INIT_BESTIOLES_NB Initial number of bestioles

COLLISION_DIE_PROB The probability to die from a collision
DEBUG_VISION Print in terminal if a bestiole can see another one
DEBUG_COLLISION Print in terminal if a bestiole collided another one
CLONE_PROB Probability that a bestiole gets cloned
DIE_PROB Probability of sudden death of a bestiole
PSYCH_CHANGEB_PROB Probability that the psycho behaviour changes behaviour
TURBO_JET_MOD How much the the accessory changes speed
SHIELD_ARMOR_MOD How much the the accessory changes armor
CLOAK_STEALTH_MOD How much the the accessory changes stealth

#sensor parameters
VISION_DIST = 100
VISION_ANGLE = 45
VISION_INTENSITY = 0.9
HEARING_DIST = 30
HEARING_INTENSITY = 0.7

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
///////////////////////////////////////////////////////////////////////////////////////

Usage:
Keyboard keys can be used as followed:

-Key Space: Spawn a clone of the first bestiole.

-Key V: Visualize sensors detection region for each bestiole.

-Key D: Used for deletion. use a keypad (only keypad) to write the id of bestiole to delete. 
Then press the key "f". Simulation will pause during input.

-Key S: Used for switching behaviour. use a keypad (only keypad) to write the id of bestiole to switch behaviour. 
Then press the key "f". Simulation will pause during input.
/////////////////////////////////////////////////////////////////////////////////////////

List of UnitTests:
==============================
0 : Normal0UnitTest 
1 : kamikazeBehaviourUnitTest
2 : gregaireBehaviourUnitTest
3 : peureuseBehaviourUnitTest
4 : prevoyanteBehaviourUnitTest
5 : psychoBehaviourUnitTest
6 : earsSensorUnitTest
7 : eyesSensorUnitTest
8 : compositeSensorUnitTest
9 : cloakAccessoryUnitTest
10 : shieldAccessoryUnitTest
11 : turboJetAccessoryUnitTest
12 : debugTest
==============================
choose a test case number 

NB: To correctly use UnitTests 1-11 make sure to use the basetest configuration file (config.txt) by calling ./build/main directly without specifying a config file
