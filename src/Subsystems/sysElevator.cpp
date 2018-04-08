/*
 * sysElevator.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */


#include "sysElevator.h"

#include "../Commands/cmdElevatorUser.h"
#include <Joystick.h>
#include <SmartDashboard/SmartDashboard.h>

sysElevator::sysElevator()
: frc::Subsystem("sysElevator"){
	AddChild("Down",lmt_StartPos );

}

void sysElevator::InitDefaultCommand(){
	SetDefaultCommand (new cmdElevatorUser());
}

void sysElevator::Log() {
}

void sysElevator::Lift(double y)
{
	m_ElevatorMC.Set(y);
	/*if (y < 0 && lmt_AllDown.Get())
	{
		m_ElevatorMC.Set(0);
	}
	else
	{
		m_ElevatorMC.Set(y);
	}*/
}
