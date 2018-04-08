/*
 * cmdDriveAuto.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#include "cmdDriveAuto.h"
#include "../Robot.h"
#include <Math.h>

cmdDriveAuto::cmdDriveAuto(double speed, double distance, double angle)
: frc::Command("cmdDriveAuto"){
	Requires(&Robot::mecDrive);

	m_Speed = speed;
	m_Angle = angle;
	m_TargetDistance = distance;

	Robot::mecDrive.g_leftFrontEncoder.Reset();
	Robot::mecDrive.g_leftRearEncoder.Reset();
	Robot::mecDrive.g_rightFrontEncoder.Reset();
	Robot::mecDrive.g_rightRearEncoder.Reset();
}

void cmdDriveAuto::Execute(){
	//Calculate the X,Y values based on the inputed angle
	double y = m_Speed * cos(m_Angle);
	double x = m_Speed * sin(m_Angle);
	Robot::mecDrive.Drive(x,y,0,0);
}

bool cmdDriveAuto::IsFinished(){

	m_CurrentDistance = abs((Robot::mecDrive.g_leftFrontEncoder.Get() * g_dDistancePerTick));
	if (m_CurrentDistance >= m_TargetDistance)
		return true;
	else
		return false;
}

void cmdDriveAuto::End(){
	Robot::mecDrive.Drive(0,0,0,0);
}

