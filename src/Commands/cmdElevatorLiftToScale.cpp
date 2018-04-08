/*
 * cmdElevatorLiftToScale.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#include "cmdElevatorLiftToScale.h"
#include "../Robot.h"

cmdElevatorLiftToScale::cmdElevatorLiftToScale(double dSpeed)
: frc::Command("cmdElevatorLiftToScale"){
	Requires(&Robot::elevator);

	SetTimeout(2.5);
	m_dSpeed=dSpeed;
}

void cmdElevatorLiftToScale::Execute(){

	Robot::elevator.Lift(m_dSpeed);

}

bool cmdElevatorLiftToScale::IsFinished(){

	return IsTimedOut();
}

void cmdElevatorLiftToScale::End(){
	Robot::elevator.Lift(0);
}


