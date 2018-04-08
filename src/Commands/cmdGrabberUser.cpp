/*
 * cmdGrabberUser.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#include "cmdGrabberUser.h"
#include "../Robot.h"

cmdGrabberUser::cmdGrabberUser()
: frc::Command("cmdGrabberUser"){
	Requires(&Robot::grabber);
}

void cmdGrabberUser::Execute(){
	auto& joystick = Robot::oi.GetDrive2Joystick();

	if (joystick.GetTrigger())
	{
		//if (Robot::grabber.m_GrabberSolenoid.Get()){
			Robot::grabber.OpenGrabber();
		//}
		//else{

		//}
	}
	else
		Robot::grabber.CloseGrabber();

}

bool cmdGrabberUser::IsFinished(){
	return false;
}

void cmdGrabberUser::End(){
	//Robot::grabber.CloseGrabber();
}


