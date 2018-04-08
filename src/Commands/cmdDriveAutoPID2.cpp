

#include "cmdDriveAutoPID2.h"
#include "../Robot.h"

cmdDriveAutoPID2::cmdDriveAutoPID2(double speed, double distance, bool direction, bool fPIDStart, bool fPIDStop)
: frc::Command("cmdDriveAuto"){
	Requires(&Robot::mecDrive);

	m_Speed = speed;
	m_Direction = direction;
	m_TargetDistance = distance;
	m_PIDStart = fPIDStart;
	m_PIDStop = fPIDStop;

}
void cmdDriveAutoPID2::Initialize(){
	Robot::mecDrive.g_leftFrontEncoder.Reset();
	Robot::mecDrive.g_leftRearEncoder.Reset();
	Robot::mecDrive.g_rightFrontEncoder.Reset();
	Robot::mecDrive.g_rightRearEncoder.Reset();
	SetTimeout(3);
}
void cmdDriveAutoPID2::Execute(){
	//Calculate the X,Y values based on the inputed angle

	double x=0; //= m_Speed * cos(m_Angle);
	double y=0; //= m_Speed * sin(m_Angle);

	if (m_Direction)
		y= m_Speed;
	else
		x = m_Speed;


	double dMultiplier = 1;

	float dLF = abs((Robot::mecDrive.g_leftFrontEncoder.Get() * g_dDistancePerTick));
	float dLR = abs((Robot::mecDrive.g_leftRearEncoder.Get() * g_dDistancePerTick));
	float dRF = abs((Robot::mecDrive.g_rightFrontEncoder.Get() * g_dDistancePerTick));
	float dRR = abs((Robot::mecDrive.g_rightRearEncoder.Get() * g_dDistancePerTick));

	if (dLF > dLR && dLF> dRF && dLF> dRR)
		m_CurrentDistance = dLF;
	else
		if (dLR > dLF && dLR > dRF && dLR > dRR)
			m_CurrentDistance = dLR;
		else
			if (dRF>dLF && dRF>dLR && dRF>dRR)
				m_CurrentDistance = dRF;
			else
				m_CurrentDistance = dRR;

	m_CurrentDistance = abs((Robot::mecDrive.g_leftFrontEncoder.Get() * g_dDistancePerTick));

	if (m_PIDStart)
	{
		if (m_Iteration < 100)
			m_Iteration = m_Iteration + 2;

		dMultiplier = m_Iteration/100;
	}

	/*if (m_PIDStop)
	{
		//Gradually slow down for the last 10%, but don't go below 25% of the speed
		if (m_TargetDistance - m_CurrentDistance <= m_TargetDistance * .1)
		{
			m_PIDStart = false; //Turn off PID Startup

			if (m_Iteration >= 27)
				m_Iteration = m_Iteration -2;

			dMultiplier = m_Iteration / 100;
		}
	}*/

	x = x * dMultiplier;
	y = y * dMultiplier;

	//Get Gyro value
	double dGyroValue;
	dGyroValue = Robot::mecDrive.m_gyro->GetAngle();

	Robot::mecDrive.Drive(x,y,0,dGyroValue);
}

bool cmdDriveAutoPID2::IsFinished(){

	if (m_CurrentDistance >= m_TargetDistance)// || IsTimedOut())
	{

		return true;
	}
	else
		return false;
}

void cmdDriveAutoPID2::End(){
	double dGyroValue;
	dGyroValue = Robot::mecDrive.m_gyro->GetAngle();


	Robot::mecDrive.g_leftFrontEncoder.Reset();
	Robot::mecDrive.g_leftRearEncoder.Reset();
	Robot::mecDrive.g_rightFrontEncoder.Reset();
	Robot::mecDrive.g_rightRearEncoder.Reset();
	Robot::mecDrive.Drive(0,0,0,dGyroValue);
}
