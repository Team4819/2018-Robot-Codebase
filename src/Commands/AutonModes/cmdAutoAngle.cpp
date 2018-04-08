/*
 * cmdAutoAngle.cpp
 *
 *  Created on: Mar 18, 2018
 *      Author: USER
 */

#include "cmdAutoAngle.h"
#include "../../Robot.h"

cmdAutoAngle::cmdAutoAngle(double angle)
: frc::Command("cmdAutoAngle"){
	Requires(&Robot::mecDrive);
	m_Angle = angle;
}

void cmdAutoAngle::Execute(){
	double dGyroValue;
	dGyroValue = Robot::mecDrive.m_gyro->GetAngle();
	double Speed = .25;
	if(m_Angle < dGyroValue)
	{
		Speed = Speed * -1;
	}
	Robot::mecDrive.Drive(0,0,Speed,0);

}

bool cmdAutoAngle::IsFinished(){
	double dGyroValue;
	dGyroValue = Robot::mecDrive.m_gyro->GetAngle();
	if( abs(dGyroValue) < 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void cmdAutoAngle::End(){}
