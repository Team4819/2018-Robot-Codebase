/*
 * sysDrive.cpp
 *
 *  Created on: Feb 18, 2018
 *      Author: Terry
 */

#include "sysDrive.h"
#include "../Commands/cmdDriveUser.h"
#include <Joystick.h>
#include <SmartDashboard/SmartDashboard.h>
//#include "../Commands/cmdDriveUser2.h"
#include "../RobotMap.h"

sysDrive::sysDrive()
: frc::Subsystem("sysDrive"){

	AddChild("Left Front Encoder", g_leftFrontEncoder);
	AddChild("Right Front Encoder", g_rightFrontEncoder);
	AddChild("Left Rear Encoder", g_leftRearEncoder);
	AddChild("Right Rear Encoder", g_rightRearEncoder);
	AddChild("NavX",m_gyro);
}

	void sysDrive::InitDefaultCommand() {
	SetDefaultCommand (new cmdDriveUser());
	}

	void sysDrive::Log() {

	}

	void sysDrive::Drive(double x, double y, double z, double gyroAngle) {
		m_robotDrive.DriveCartesian(x,y,z,gyroAngle);
	}





