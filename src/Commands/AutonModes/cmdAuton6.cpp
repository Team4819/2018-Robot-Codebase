
#include "cmdAuton6.h"
#include "../cmdDriveAutoPID2.h"
#include "../cmdElevatorLiftAuto.h"
#include "../cmdElevatorLiftToSwitch.h"
#include "../cmdElevatorLiftToScale.h"
#include "../cmdGrabberAuto.h"

cmdAuton6::cmdAuton6(char cHotSwitch, char cHotScale) {

	//Starting on the left (against the portal), move past switch

	//Make sure grabber is closed
	AddSequential(new cmdGrabberAuto('C'));

	//Gently lift to start position
	AddSequential(new cmdElevatorLiftAuto(.25,.5));

	AddSequential(new cmdDriveAutoPID2(.80,12,true,true,true));

	if (cHotScale=='L')
		{
		//strafe right pushing against the switch wall
		AddSequential(new cmdDriveAutoPID2(.80,12,false,true,true));
		//Lift to Scale position
		AddParallel(new cmdElevatorLiftToScale(.75));
		//Drive forward 10 feet
		AddSequential(new cmdDriveAutoPID2(.65,120,true,true,true));
		//Strafe right 1 foot
		AddSequential(new cmdDriveAutoPID2(.65,12,false,true,true));
		//Drive forward .5 foot
		AddSequential(new cmdDriveAutoPID2(.65,6,true,true,true));
		//Open Grabber
		AddSequential(new cmdGrabberAuto('O'));
		//Backup
		AddSequential(new cmdDriveAutoPID2(-.65,12,true,true,true));
		//Lower elevator
		AddSequential(new cmdElevatorLiftAuto(-.75,2));
		}
	else
	{

	}
}


