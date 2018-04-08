/*
 * cmdElevatorLiftAuto.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_COMMANDS_CMDELEVATORLIFTAUTO_H_
#define SRC_COMMANDS_CMDELEVATORLIFTAUTO_H_


#include <Commands/Command.h>

class cmdElevatorLiftAuto : public frc::Command{
public:
	cmdElevatorLiftAuto(double dSpeed, double dTimeInSeconds);
	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double m_dSpeed;
};


#endif /* SRC_COMMANDS_CMDELEVATORLIFTAUTO_H_ */
