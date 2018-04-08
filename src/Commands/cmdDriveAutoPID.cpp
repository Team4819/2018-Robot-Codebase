#include "cmdDriveAutoPID.h"
#include "../Robot.h"

cmdDriveAutoPID::cmdDriveAutoPID(double speed, double distance, double angle, bool fPIDStart, bool fPIDStop)
: frc::Command("cmdDriveAuto"){
	Requires(&Robot::mecDrive);

	m_Speed = speed;
	m_Angle = angle;
	m_TargetDistance = distance;
	m_PIDStart = fPIDStart;
	m_PIDStop = fPIDStop;

}

void cmdDriveAutoPID::Initialize(){

	Robot::mecDrive.g_leftFrontEncoder.Reset();
	Robot::mecDrive.g_leftRearEncoder.Reset();
	Robot::mecDrive.g_rightFrontEncoder.Reset();
	Robot::mecDrive.g_rightRearEncoder.Reset();
	SetTimeout(4);
}
void cmdDriveAutoPID::Execute(){
	//Calculate the X,Y values based on the inputed angle

	double dAngle = m_Angle;

	if (m_Angle > 90)
		dAngle = 180 - m_Angle;

	double x = m_Speed * cos(dAngle);
	double y = m_Speed * sin(dAngle);

	if (m_Angle > 90)
		x = x * -1;

	double dMultiplier = 1;

	m_CurrentDistance = abs((Robot::mecDrive.g_leftFrontEncoder.Get() * g_dDistancePerTick));

	if (m_PIDStart)
	{
		if (m_Iteration < 100)
			m_Iteration = m_Iteration + 2;

		dMultiplier = m_Iteration/100;
	}

	if (m_PIDStop)
	{
		//Gradually slow down for the last 10%, but don't go below 25% of the speed
		if (m_TargetDistance - m_CurrentDistance <= m_TargetDistance * .1)
		{
			m_PIDStart = false; //Turn off PID Startup

			if (m_Iteration >= 27)
				m_Iteration = m_Iteration -2;

			dMultiplier = m_Iteration / 100;
		}
	}

	x = x * dMultiplier;
	y = y * dMultiplier;

	//Get Gyro value
	//double dGyroValue = 0;
	double dGyroValue;
	dGyroValue = Robot::mecDrive.m_gyro->GetAngle();

	Robot::mecDrive.Drive(x,y,0,dGyroValue);
}

bool cmdDriveAutoPID::IsFinished(){

	if (m_CurrentDistance >= m_TargetDistance||IsTimedOut())
		return true;
	else
		return false;
}

void cmdDriveAutoPID::End(){
	double dGyroValue;
	dGyroValue = Robot::mecDrive.m_gyro->GetAngle();
	Robot::mecDrive.Drive(0,0,0, dGyroValue);
}
