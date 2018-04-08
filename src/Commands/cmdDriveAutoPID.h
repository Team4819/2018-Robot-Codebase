/*
 * cmdDriveAutoPID.h
 *
 *  Created on: Mar 16, 2018
 *      Author: e01388
 */

#ifndef SRC_COMMANDS_CMDDRIVEAUTOPID_H_
#define SRC_COMMANDS_CMDDRIVEAUTOPID_H_

#include <Commands/Command.h>

class cmdDriveAutoPID : public frc::Command{
public:
	cmdDriveAutoPID(double speed, double distance, double angle, bool fPIDStart, bool fPIDStop);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double m_TargetDistance = 0;
	double m_CurrentDistance = 0;

	double m_Speed;
	double m_Angle;
	int m_Iteration = 0;
	int m_StopIteration = 100;

	bool m_PIDStart = false;
	bool m_PIDStop = false;

};



#endif /* SRC_COMMANDS_CMDDRIVEAUTOPID_H_ */
