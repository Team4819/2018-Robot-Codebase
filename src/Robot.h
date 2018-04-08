/*
 * Robot.h
 *
 *  Created on: Feb 18, 2018
 *      Author: Terry
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Subsystems/sysDrive.h"
#include "Subsystems/sysGrabber.h"
#include "Subsystems/sysElevator.h"
#include "Subsystems/sysClimber.h"

#include <Commands/cmdAuto.h>

#include "OI.h"
#include <DigitalOutput.h>
#include <Compressor.h>

class Robot : public frc::IterativeRobot{
public:
	static sysDrive mecDrive;
	static sysGrabber grabber;
	static sysElevator elevator;
	static sysClimber climber;
	static OI oi;


	char g_HotSwitch = 'L';
	char g_HotScale = 'L';
	float g_Voltage = 5.00;

private:

	//cmdAuto m_autonomousCommand;
	Command* m_autonomousCommand= nullptr;
	frc::Compressor m_compressor{0};

	frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
	void DisabledInit() override;

};


#endif /* SRC_ROBOT_H_ */
