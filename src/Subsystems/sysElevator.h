/*
 * sysElevator.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_SUBSYSTEMS_SYSELEVATOR_H_
#define SRC_SUBSYSTEMS_SYSELEVATOR_H_


#include <Spark.h>
#include <DigitalInput.h>
#include <Commands/Subsystem.h>

#include "../RobotMap.h"

class sysElevator : public frc::Subsystem{
public:
	sysElevator();

	void InitDefaultCommand() override;

	void Log();

	void Lift(double y);

	DigitalInput lmt_StartPos{g_iLimitStart};
	DigitalInput lmt_AllDown{g_iLimitALLDown};
	DigitalInput lmt_SwitchPos{g_iLimitSwitchPos};

private:

	frc::Spark m_ElevatorMC{g_iElevatorMCID};

};

#endif /* SRC_SUBSYSTEMS_SYSELEVATOR_H_ */
