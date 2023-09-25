# ConfigFanshawe
 Repo containing the code for Configuraton and Deployment taught in Fanshawe GDP-1


Installion notes:

Step 1: Pull the Repository
Step 2: Open the ConfigFanshwe.sln and compile the entire solution

Usage:

1: Set TestSuiteOne_StaticLib as the startup project and build+run to run testnng on the Player Static Lib
2: Set TestSuiteTwo_DynamicLib as the startup project and build+run to run tests on the Dungeon DLL 
3: Set TestSuiteThree_Integration as the startup project and build+run to test integration of noth the static and dynamic library classes

Debugging:

If the building/running of any of the classes fail its probably because either/both of ConfigStaticLib and ConfigDynamicLib projects haven't been built
Just build those 2 projects and the tryagain
