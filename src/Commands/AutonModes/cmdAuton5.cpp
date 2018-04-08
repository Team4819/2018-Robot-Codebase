
#include "cmdAuton5.h"
#include "../cmdDriveAutoPID.h"
#include "../cmdElevatorLiftAuto.h"
#include "../cmdElevatorLiftToSwitch.h"
#include "../cmdElevatorLiftToScale.h"
#include "../cmdGrabberAuto.h"

cmdAuton5::cmdAuton5(char cHotSwitch, char cHotScale) {

	//Starting on the left (against the portal), move to a LEFT hot scale or move past it

	//Make sure grabber is closed
	AddSequential(new cmdGrabberAuto('C'));

	//Gently lift to start position
	AddSequential(new cmdElevatorLiftAuto(-.25,.5));

	if (cHotSwitch=='R')
	{
		//Lift to switch position
		AddParallel(new cmdElevatorLiftToSwitch(.75));
		//Drive forward 11.5 feet at a -10 degree angle
		AddSequential(new cmdDriveAutoPID(.65,138,-10,true,true));
	}
	else
	{
		//Drive forward 14 feet
		AddSequential(new cmdDriveAutoPID(.65,168,0,true,true));

		if (cHotScale=='R')
		{
			//strafe Left pushing against the switch wall
			AddSequential(new cmdDriveAutoPID(.80,12,90,true,true));
			//Lift to Scale position
			AddParallel(new cmdElevatorLiftToScale(-.75));
			//Drive forward 10 feet
			AddSequential(new cmdDriveAutoPID(.65,120,0,true,true));
			//Strafe left 1 foot
			AddSequential(new cmdDriveAutoPID(.65,12,-90,true,true));
			//Drive forward .5 foot
			AddSequential(new cmdDriveAutoPID(.65,6,0,true,true));
			//Open Grabber
			AddSequential(new cmdGrabberAuto('O'));
			//Backup
			AddSequential(new cmdDriveAutoPID(-.65,12,0,true,true));
			//Lower elevator
			AddSequential(new cmdElevatorLiftAuto(.75,2));
		}
	}
}


