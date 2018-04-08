#ifndef cmdClimberUser_H
#define cmdClimberUser_H

#include <Commands/Command.h>

class cmdClimberUser : public frc::Command {
public:
	cmdClimberUser();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // cmdClimberUser_H
