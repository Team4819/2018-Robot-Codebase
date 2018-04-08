/*
 * cmdElevatorLiftToSwitch.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_COMMANDS_CMDELEVATORLIFTTOSWITCH_H_
#define SRC_COMMANDS_CMDELEVATORLIFTTOSWITCH_H_


#include <Commands/Command.h>

class cmdElevatorLiftToSwitch : public frc::Command{
public:
	cmdElevatorLiftToSwitch(double dSpeed);
	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double m_dSpeed;
};


#endif /* SRC_COMMANDS_CMDELEVATORLIFTTOSWITCH_H_ */
