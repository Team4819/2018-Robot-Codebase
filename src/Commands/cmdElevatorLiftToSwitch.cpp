/*
 * cmdElevatorLiftToSwitch.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#include "cmdElevatorLiftToSwitch.h"
#include "../Robot.h"

cmdElevatorLiftToSwitch::cmdElevatorLiftToSwitch(double dSpeed)
: frc::Command("cmdElevatorLiftToSwitch"){
	Requires(&Robot::elevator);

	m_dSpeed=dSpeed;
}

void cmdElevatorLiftToSwitch::Execute(){

	Robot::elevator.Lift(m_dSpeed);
}

bool cmdElevatorLiftToSwitch::IsFinished(){
	return Robot::elevator.lmt_SwitchPos.Get();
}

void cmdElevatorLiftToSwitch::End(){
	Robot::elevator.Lift(0);
}



