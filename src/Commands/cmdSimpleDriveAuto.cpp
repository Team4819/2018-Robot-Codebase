#include "cmdSimpleDriveAuto.h"
#include "../Robot.h"
#include "../RobotMap.h"

cmdSimpleDriveAuto::cmdSimpleDriveAuto(double distance, bool direction) : frc::Command("cmdSimpleCriveAuto") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::mecDrive);
	m_Targetdistance = distance;
	m_bool = direction;
}

// Called just before this Command runs the first time
void cmdSimpleDriveAuto::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void cmdSimpleDriveAuto::Execute() {

	double a = (Robot::mecDrive.m_gyro->GetYaw());
	double p = (m_Targetdistance - (Robot::mecDrive.g_leftFrontEncoder.Get() * g_dDistancePerTick)) * .25;
	if (p >= .5){
		p = .5;
	}
	if (p <= -.5){
		p = -.5;
	}

	if (m_bool == true){
		Robot::mecDrive.Drive(p, 0, 0, a);
	}
	else{
		Robot::mecDrive.Drive(0, p, 0, a);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool cmdSimpleDriveAuto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cmdSimpleDriveAuto::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdSimpleDriveAuto::Interrupted() {

}
