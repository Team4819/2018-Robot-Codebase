#ifndef cmdSimpleDriveAuto_H
#define cmdSimpleDriveAuto_H

#include <Commands/Command.h>

class cmdSimpleDriveAuto : public  frc::Command {
public:
	cmdSimpleDriveAuto(double distance, bool direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_Targetdistance = 0;
	double m_Currentdistance = 0;
	bool m_bool;
};

#endif  // cmdSimpleDriveAuto_H
