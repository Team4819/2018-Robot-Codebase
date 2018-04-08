#include "sysClimber.h"
#include "../RobotMap.h"
#include "Commands/cmdClimberUser.h"

sysClimber::sysClimber() : frc::Subsystem("sysClimber") {

}

void sysClimber::InitDefaultCommand() {
	SetDefaultCommand(new cmdClimberUser());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void sysClimber::Lift(double x){
	m_ClimberMC.Set(x);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
