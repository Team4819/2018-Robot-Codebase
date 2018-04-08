/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Buttons/JoystickButton.h>
#include <Joystick.h>
#include <XboxController.h>

class OI {
public:
	OI();

	frc::Joystick& GetDrive1Joystick();
	frc::Joystick& GetDrive2Joystick();
	frc::JoystickButton& GetFullDownButton();
	frc::JoystickButton& GetClimberButton();
private:
	frc::Joystick m_Drive1{0};
	frc::Joystick m_Drive2{1};

	frc::JoystickButton m_dGrabOpen{&m_Drive2,5};
	frc::JoystickButton m_dGrabClose{&m_Drive2,6};
	frc::JoystickButton m_FullDown{&m_Drive2,7};
	frc::JoystickButton m_Climb{&m_Drive2,10};
};
