/*
 * cmdGrabberAuto.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_COMMANDS_CMDGRABBERAUTO_H_
#define SRC_COMMANDS_CMDGRABBERAUTO_H_
#include <Commands/Command.h>

class cmdGrabberAuto : public frc::Command{
public:
	cmdGrabberAuto(char cDirection);
	void Execute() override;
	bool IsFinished() override;
	void End() override;

	bool g_fOpen;
};




#endif /* SRC_COMMANDS_CMDGRABBERAUTO_H_ */
