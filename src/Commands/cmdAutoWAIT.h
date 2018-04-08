/*
 * cmdAutoWAIT.h
 *
 *  Created on: Mar 26, 2018
 *      Author: USER
 */

#ifndef SRC_COMMANDS_CMDAUTOWAIT_H_
#define SRC_COMMANDS_CMDAUTOWAIT_H_

#include <Commands/Command.h>

class cmdAutoWAIT : public frc::Command{
public:
	cmdAutoWAIT(double dWaitTime);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double m_WaitTime;
};

#endif /* SRC_COMMANDS_CMDAUTOWAIT_H_ */
