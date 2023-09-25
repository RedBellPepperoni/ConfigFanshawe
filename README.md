# ConfigFanshawe<br>
 Repo containing the code for Configuraton and Deployment taught in Fanshawe GDP-1<br>
<br>

Installion notes:<br>
<br>
> Step 1: Pull the Repository<br>
>
> Step 2: Open the ConfigFanshawe.sln and compile the entire solution<br>
<br>



Usage:<br>
<br> 
>1: Set [TestSuiteOne_StaticLib](https://github.com/RedBellPepperoni/ConfigFanshawe/blob/main/TestSuiteOne_StaticLib/TestSuiteOne_StaticLib.vcxproj "TestSuiteOne") as the startup project and build+run to run testing on the Player Static Lib<br>
>
>2: Set [TestSuiteTwo_DynamicLib](https://github.com/RedBellPepperoni/ConfigFanshawe/blob/main/TestSuiteTwo_DynamicLib/TestSuiteTwo_DynamicLib.vcxproj "TestSuiteTwo") as the startup project and build+run to run tests on the Dungeon DLL<br>
>
>3: Set [TestSuiteThree_Integration](https://github.com/RedBellPepperoni/ConfigFanshawe/blob/main/TestSuiteThree_Integration/TestSuiteThree_Integration.vcxproj "TestSuiteThree") as the startup project and build+run to test integration of both the static and dynamic library classes<br>
>
<br>



Debugging:<br>
<br>
>If the building/running of any of the classes fail its probably because either/both of [ConfigStaticLib](https://github.com/RedBellPepperoni/ConfigFanshawe/blob/main/ConfigStaticLib/ConfigStaticLib.vcxproj "ConfigStaticLib") and [ConfigDynamicLib](https://github.com/RedBellPepperoni/ConfigFanshawe/blob/main/ConfigDynamicLib/ConfigDynamicLib.vcxproj "ConfigDynamicLib") projects haven't been built<br>
>
>Just build those 2 projects and the try again<br>
