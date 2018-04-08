
#include "Robot.h"
#include <iostream>
#include <DriverStation.h>
#include <DigitalOutput.h>

sysDrive Robot::mecDrive;
sysGrabber Robot::grabber;
sysElevator Robot::elevator;
sysClimber Robot::climber;
OI Robot::oi;


DigitalOutput m_ArduinoOutput{14};

void Robot::RobotInit() {
	// Show what command your subsystem is running on the SmartDashboard
	frc::SmartDashboard::PutData(&mecDrive);
	frc::SmartDashboard::PutData(&grabber);
	frc::SmartDashboard::PutData(&elevator);
	m_ArduinoOutput.Set(false);
	m_compressor.Start();
}

void Robot::AutonomousInit() {
	Robot::mecDrive.g_leftFrontEncoder.Reset();
	Robot::mecDrive.g_leftRearEncoder.Reset();
	Robot::mecDrive.g_rightFrontEncoder.Reset();
	Robot::mecDrive.g_rightRearEncoder.Reset();
	Robot::mecDrive.m_gyro->Reset();


	m_autonomousCommand = new cmdAuto();



	m_autonomousCommand->Start();
	std::cout << "Starting Auto" << std::endl;
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand!=nullptr)
		m_autonomousCommand->Cancel();

		//m_ArduinoOutput.Set(true);
		Robot::mecDrive.g_leftFrontEncoder.Reset();
		Robot::mecDrive.g_leftRearEncoder.Reset();
		Robot::mecDrive.g_rightFrontEncoder.Reset();
		Robot::mecDrive.g_rightRearEncoder.Reset();
		Robot::mecDrive.m_gyro->Reset();

	std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();

}

void Robot::DisabledInit(){
	//m_ArduinoOutput.Set(false);
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
