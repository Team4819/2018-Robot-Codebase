/*
 * cmdAutoAngle.h
 *
 *  Created on: Mar 18, 2018
 *      Author: USER
 */

#ifndef SRC_COMMANDS_AUTONMODES_CMDAUTOANGLE_H_
#define SRC_COMMANDS_AUTONMODES_CMDAUTOANGLE_H_

#include <Commands/Command.h>

class cmdAutoAngle : public frc::Command {
public:
	cmdAutoAngle(double angle);
	void Execute();
	bool IsFinished();
	void End();

private:
	double m_Angle;
};





#endif /* SRC_COMMANDS_AUTONMODES_CMDAUTOANGLE_H_ */
