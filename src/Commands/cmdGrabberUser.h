/*
 * cmdGrabberUser.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_COMMANDS_CMDGRABBERUSER_H_
#define SRC_COMMANDS_CMDGRABBERUSER_H_

#include <Commands/Command.h>

class cmdGrabberUser : public frc::Command{
public:
	cmdGrabberUser();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
};




#endif /* SRC_COMMANDS_CMDGRABBERUSER_H_ */
