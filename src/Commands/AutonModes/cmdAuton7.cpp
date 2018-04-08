/*
 * cmdAuton7.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: Noah
 */


#include "cmdAuton7.h"
#include "../cmdDriveAutoPID2.h"
#include "cmdAutoAngle.h"
#include <DriverStation.h>

cmdAuton7::cmdAuton7(char cHotSwitch)
{
	//Drive forward 11 feet
	AddSequential(new cmdDriveAutoPID2(.2,125,true,true,true));
	AddSequential(new cmdAutoAngle(90));
}

