#include "cmdAuton3.h"
#include "../cmdDriveAutoPID2.h"
#include "../cmdElevatorLiftAuto.h"
#include "../cmdGrabberAuto.h"
#include "../cmdAutoWAIT.h"
#include "cmdAutoResetEncoders.h"
#include "cmdAutoAngle.h"
#include <DriverStation.h>

cmdAuton3::cmdAuton3(char cHotSwitch) {

	//Make sure grabber is closed
		AddSequential(new cmdGrabberAuto('C'));
		//AddParallel(new cmdAutoAngle(0));

		//Gently lift to start position
		AddSequential(new cmdElevatorLiftAuto(-.25,.5));
		AddParallel(new cmdElevatorLiftAuto(-.6,3));
		AddSequential(new cmdDriveAutoPID2(.35, 5, true,true,true));

		AddSequential(new cmdAutoResetEncoders());

		if (cHotSwitch=='L')
		{
			//Turn to angle -45
			AddSequential(new cmdAutoAngle(-45));
			AddSequential(new cmdAutoResetEncoders());
			AddSequential(new cmdDriveAutoPID2(.40, 25, true, true, true));
		}
		else
		{
			//Turn to angle 45
			AddSequential(new cmdAutoAngle(45));
			AddSequential(new cmdAutoResetEncoders());
			AddSequential(new cmdDriveAutoPID2(.40, 25, true, true, true));
		}

		AddSequential(new cmdAutoAngle(0));
		AddSequential(new cmdAutoResetEncoders());
		//forward to the switch
		AddSequential(new cmdDriveAutoPID2(.5, 30, true, true, true));

		AddSequential(new cmdAutoWAIT(1));
		AddSequential(new cmdGrabberAuto('O'));
}
