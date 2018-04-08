/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef SRC_COMMANDS_CMDAUTON_H_
#define SRC_COMMANDS_CMDAUTON_H_

#include <Commands/CommandGroup.h>

class cmdAuton : public frc::CommandGroup {
public:
	cmdAuton();
	void Execute() override;

	bool IsFinished() override;
	void End() override;


};

#endif
