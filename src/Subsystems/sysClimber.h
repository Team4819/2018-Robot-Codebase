#ifndef sysClimber_H
#define sysClimber_H

#include <Spark.h>
#include <Commands/Subsystem.h>

#include "../RobotMap.h"

class sysClimber : public frc::Subsystem {
private:
	frc::Spark m_ClimberMC{g_iClimberMCID};
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	sysClimber();
	void InitDefaultCommand();

	void Lift(double x);
};

#endif  // sysClimber_H
