#include "cmdClimberUser.h"
#include "../Robot.h"

cmdClimberUser::cmdClimberUser() : frc::Command("cmdElevatorUser") {
	Requires(&Robot::climber);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void cmdClimberUser::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void cmdClimberUser::Execute() {
	auto& joystick = Robot::oi.GetDrive2Joystick();
	auto& Button1 = Robot::oi.GetClimberButton();

	if(Button1.Get() == true)
		Robot::climber.Lift(joystick.GetY() * -1);
	else
		Robot::climber.Lift(0);
}

// Make this return true when this Command no longer needs to run execute()
bool cmdClimberUser::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void cmdClimberUser::End() {
	Robot::climber.Lift(0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void cmdClimberUser::Interrupted() {

}
