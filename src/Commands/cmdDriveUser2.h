/*
 * cmdDriveUser2.h
 *
 *  Created on: Mar 25, 2018
 *      Author: Noah
 */

#ifndef SRC_COMMANDS_CMDDRIVEUSER2_H_
#define SRC_COMMANDS_CMDDRIVEUSER2_H_

#include <Commands/Command.h>

class cmdDriveUser2 : public frc::Command{
public:
	cmdDriveUser2();
	void Execute() override;
	bool IsFinished() override;
	void End() override;
};



#endif /* SRC_COMMANDS_CMDDRIVEUSER2_H_ */
