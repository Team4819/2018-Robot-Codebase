/*
 * cmdAutoResetEncoders.cpp
 *
 *  Created on: Mar 16, 2018
 *      Author: USER
 */

#include "../../Robot.h"
#include "cmdAutoResetEncoders.h"
#include <Timer.h>

cmdAutoResetEncoders::cmdAutoResetEncoders()
{

}

void cmdAutoResetEncoders::Excute(){
	//SetTimeout(5000);
	Wait(50);
	Robot::mecDrive.g_leftFrontEncoder.Reset();
	Robot::mecDrive.g_leftRearEncoder.Reset();
	Robot::mecDrive.g_rightFrontEncoder.Reset();
	Robot::mecDrive.g_rightRearEncoder.Reset();
}

bool cmdAutoResetEncoders::IsFinished(){
	return true;
}
