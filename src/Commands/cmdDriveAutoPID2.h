/*
 * cmdDriveAutoPID.h
 *
 *  Created on: Mar 16, 2018
 *      Author: e01388
 */

#ifndef SRC_COMMANDS_CMDDRIVEAUTOPID2_H_
#define SRC_COMMANDS_CMDDRIVEAUTOPID2_H_

#include <Commands/Command.h>

class cmdDriveAutoPID2 : public frc::Command{
public:
	cmdDriveAutoPID2(double speed, double distance, bool direction, bool fPIDStart, bool fPIDStop);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double m_TargetDistance = 0;
	double m_CurrentDistance = 0;

	double m_Speed;
	bool m_Direction = false;
	int m_Iteration = 0;
	int m_StopIteration = 100;

	bool m_PIDStart = false;
	bool m_PIDStop = false;

};



#endif /* SRC_COMMANDS_CMDDRIVEAUTOPID_H_ */
