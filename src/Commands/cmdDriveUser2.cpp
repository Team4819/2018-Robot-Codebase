/*
 * cmdDriveUser2.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: Noah
 */



#include "cmdDriveUser2.h"
#include "DriverStation.h"
#include "../Robot.h"

cmdDriveUser2::cmdDriveUser2()
: frc::Command("cmdDriveUser2"){
	Requires(&Robot::mecDrive);
}

void cmdDriveUser2::Execute(){
  auto& joystick = Robot::oi.GetDrive1Joystick();
  float rotation = 0;
  if(joystick.GetRawAxis(2) > 0)
	  rotation = abs(joystick.GetRawAxis(2)) ;
  else
  {
	  if(joystick.GetRawAxis(3) > 0)
	   rotation = abs(joystick.GetRawAxis(3)) * -1;
	  else
		  rotation = 0;
  }
  Robot::mecDrive.Drive(joystick.GetX() , joystick.GetY() * -1,rotation ,0);
  frc::SmartDashboard::PutNumber("Left Trigger",joystick.GetRawAxis(2));
  frc::SmartDashboard::PutNumber("Right Trigger",joystick.GetRawAxis(3));

}

bool cmdDriveUser2::IsFinished(){
	return false;
}

void cmdDriveUser2::End(){
	Robot::mecDrive.Drive(0,0,0,0);
}
