/*
 * cmdDriveAuto.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_COMMANDS_CMDDRIVEAUTO_H_
#define SRC_COMMANDS_CMDDRIVEAUTO_H_

#include <Commands/Command.h>

class cmdDriveAuto : public frc::Command{
public:
	cmdDriveAuto(double speed, double distance, double angle);
	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double m_TargetDistance = 0;
	double m_CurrentDistance = 0;

	double m_Speed;
	double m_Angle;

};



#endif /* SRC_COMMANDS_CMDDRIVEAUTO_H_ */
