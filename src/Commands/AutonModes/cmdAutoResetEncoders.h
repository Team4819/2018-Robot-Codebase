/*
 * cmdAutoResetEncoders.h
 *
 *  Created on: Mar 16, 2018
 *      Author: USER
 */

#ifndef SRC_COMMANDS_AUTONMODES_CMDAUTORESETENCODERS_H_
#define SRC_COMMANDS_AUTONMODES_CMDAUTORESETENCODERS_H_

#include <Commands/CommandGroup.h>

class cmdAutoResetEncoders : public frc::CommandGroup {
public:
	cmdAutoResetEncoders();
	void Excute();
	bool IsFinished();
};



#endif /* SRC_COMMANDS_AUTONMODES_CMDAUTORESETENCODERS_H_ */
