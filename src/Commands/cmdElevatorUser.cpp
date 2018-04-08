/*
 * cmdElevator.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */


#include "cmdElevatorUser.h"
#include "../Robot.h"

cmdElevatorUser::cmdElevatorUser()
: frc::Command("cmdElevatorUser"){
	Requires(&Robot::elevator);
}

void cmdElevatorUser::Execute(){
	auto& joystick = Robot::oi.GetDrive2Joystick();
	auto& Button0 = Robot::oi.GetFullDownButton();
	auto& Button1 = Robot::oi.GetClimberButton();
	float speed = 0;
	if (Robot::elevator.lmt_StartPos.Get()==false)
	{
		if (joystick.GetY() > 0)
			speed = joystick.GetY() * -1;
		else
			if (Button0.Get() == true)
				speed = joystick.GetY() * -1;
			else
				speed = 0;
	}
	else
		speed = joystick.GetY() * -1;
	if(Button1.Get())
		speed = speed * .15;
	Robot::elevator.Lift(speed);
}

bool cmdElevatorUser::IsFinished(){
	return false;
}

void cmdElevatorUser::End(){
	Robot::elevator.Lift(0);
}

