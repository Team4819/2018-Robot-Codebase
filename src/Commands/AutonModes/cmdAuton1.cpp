/*
 * cmdAuton1.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */


#include "cmdAuton1.h"
#include "../cmdDriveAutoPID2.h"
#include "cmdAutoAngle.h"


cmdAuton1::cmdAuton1() {
	//Drive forward 11 feet
	AddSequential(new cmdDriveAutoPID2(.2,125,true,true,true));
	//AddParallel(new cmdAutoAngle(0));
}


