/*
 * cmdElevator.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_COMMANDS_CMDELEVATORUSER_H_
#define SRC_COMMANDS_CMDELEVATORUSER_H_


#include <Commands/Command.h>

class cmdElevatorUser : public frc::Command{
public:
	cmdElevatorUser();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
};


#endif /* SRC_COMMANDS_CMDELEVATORUSER_H_ */
