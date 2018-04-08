/*
 * cmdDriveUser.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: Terry
 */



#include "cmdDriveUser.h"
#include "../Robot.h"

cmdDriveUser::cmdDriveUser()
: frc::Command("cmdDriveUser"){
	Requires(&Robot::mecDrive);
}

void cmdDriveUser::Execute(){
  auto& joystick = Robot::oi.GetDrive1Joystick();
  Robot::mecDrive.Drive(joystick.GetX() , joystick.GetY() * -1, joystick.GetZ(),0);
}

bool cmdDriveUser::IsFinished(){
	return false;

}

void cmdDriveUser::End(){
	Robot::mecDrive.Drive(0,0,0,0);
}
