/*
 * cmdDriveUser.h
 *
 *  Created on: Feb 18, 2018
 *      Author: Terry
 */

#ifndef SRC_COMMANDS_CMDDRIVEUSER_H_
#define SRC_COMMANDS_CMDDRIVEUSER_H_

#include <Commands/Command.h>

class cmdDriveUser : public frc::Command{
public:
	cmdDriveUser();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
};



#endif /* SRC_COMMANDS_CMDDRIVEUSER_H_ */
