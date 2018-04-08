
#include "cmdAuton2.h"
#include "cmdAutoResetEncoders.h"
#include "../cmdDriveAutoPID2.h"
#include "../cmdElevatorLiftAuto.h"
#include "../cmdElevatorLiftToSwitch.h"
#include "../cmdGrabberAuto.h"
#include "../cmdDriveAuto.h"
#include "../cmdSimpleDriveAuto.h"
#include "../cmdAutoWAIT.h"
#include "cmdAutoAngle.h"
#include <DriverStation.h>

cmdAuton2::cmdAuton2(char cHotSwitch) {

	//Make sure grabber is closed
	AddSequential(new cmdGrabberAuto('C'));
	//AddParallel(new cmdAutoAngle(0));

	//Gently lift to start position
	AddSequential(new cmdElevatorLiftAuto(-.25,.5));
	AddParallel(new cmdElevatorLiftAuto(-.6,3));
	AddSequential(new cmdDriveAutoPID2(.35, 5, true,true,true));

	AddSequential(new cmdAutoResetEncoders());

	if (cHotSwitch=='L')
		//sideways to the left
		AddSequential(new cmdDriveAutoPID2(-.40, 25, false, true, true));
	else
		//sideways to the right
		AddSequential(new cmdDriveAutoPID2(.40, 25, false, true, true));

	AddSequential(new cmdAutoAngle(0));
	AddSequential(new cmdAutoResetEncoders());
	//forward to the switch
	AddSequential(new cmdDriveAutoPID2(.5, 30, true, true, true));
	//Wait for coast to stop and recheck gamedata

	AddSequential(new cmdAutoWAIT(1));
	AddSequential(new cmdGrabberAuto('O'));
	//std::string GameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	//if(GameData.length() > 0)
	//{
	//	if(GameData[0]==cHotSwitch)
			//Open Grabber
			//AddSequential(new cmdGrabberAuto('O'));
	//	else
			//Backup
	//		AddSequential(new cmdDriveAutoPID2(-.25,2,true,true,true));
	//}


}


