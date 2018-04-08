/*
 * cmdGrabberAuto.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */


#include "cmdGrabberAuto.h"
#include "../Robot.h"

cmdGrabberAuto::cmdGrabberAuto(char cDirection)
: frc::Command("cmdGrabberAuto"){
	Requires(&Robot::grabber);

	SetTimeout(2);

	if (cDirection == 'O')
		g_fOpen = true;
	else
		g_fOpen = false;
}

void cmdGrabberAuto::Execute(){

	if (g_fOpen){
		Robot::grabber.OpenGrabber();
	}
	else{
		Robot::grabber.CloseGrabber();
	}
}



bool cmdGrabberAuto::IsFinished(){
	return IsTimedOut();
}

void cmdGrabberAuto::End(){
	Robot::grabber.CloseGrabber();
}

