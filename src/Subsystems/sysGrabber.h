/*
 * sysGrabber.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_SUBSYSTEMS_SYSGRABBER_H_
#define SRC_SUBSYSTEMS_SYSGRABBER_H_


#include <Solenoid.h>
#include <Commands/Subsystem.h>

#include "../RobotMap.h"

class sysGrabber : public frc::Subsystem{
public:
	sysGrabber();
	void InitDefaultCommand() override;

	void OpenGrabber();

	void CloseGrabber();

	bool g_fGrabberOpen;

	frc::Solenoid m_GrabberSolenoid {0};
private:



};

#endif /* SRC_SUBSYSTEMS_SYSGRABBER_H_ */
