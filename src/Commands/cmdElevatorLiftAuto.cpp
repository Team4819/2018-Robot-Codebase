/*
 * cmdElevatorLiftAuto.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */


#include "cmdElevatorLiftAuto.h"
#include "../Robot.h"

cmdElevatorLiftAuto::cmdElevatorLiftAuto(double dSpeed, double dTimeInSeconds)
: frc::Command("cmdElevatorLiftToSwitch"){
	Requires(&Robot::elevator);

	SetTimeout(dTimeInSeconds);

	m_dSpeed=dSpeed;
}

void cmdElevatorLiftAuto::Execute(){

	Robot::elevator.Lift(m_dSpeed);
}

bool cmdElevatorLiftAuto::IsFinished(){

	return IsTimedOut();
}

void cmdElevatorLiftAuto::End(){
	Robot::elevator.Lift(0);
}

