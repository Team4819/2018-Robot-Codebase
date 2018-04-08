/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "cmdAuton.h"
#include <Commands/AutonModes/cmdAuton1.h>
#include <Commands/AutonModes/cmdAuton2.h>
#include <Commands/AutonModes/cmdAuton3.h>
#include <Commands/AutonModes/cmdAuton4.h>
#include <Commands/AutonModes/cmdAuton5.h>
#include <DriverStation.h>
#include <AnalogInput.h>
#include <SmartDashboard/SmartDashboard.h>


AnalogInput m_ASwitch{0};

cmdAuton::cmdAuton() {
}

void cmdAuton::Execute(){
	char cAutonHotSwitch = 'L';
	char cAutonHotScale = 'L';

	//Get Data from Hot switch / scale
	std::string sGameData;
	sGameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	if (sGameData.length() > 0)
	{
		cAutonHotSwitch = sGameData[0];
		cAutonHotScale = sGameData[1];
	}

	double m_SV = m_ASwitch.GetVoltage();

	frc::SmartDashboard::PutNumber("AutonSwitchV",m_SV);
	frc::SmartDashboard::PutString("AutonGameData", sGameData);

	if(m_SV > 4.75 )
		AddSequential(new cmdAuton1());
	else if (m_SV > 4.25)
		AddSequential(new cmdAuton2(cAutonHotSwitch));
	else if (m_SV > 3.75)
		AddSequential(new cmdAuton3(cAutonHotSwitch));
	else if (m_SV > 3.25)
		AddSequential(new cmdAuton4(cAutonHotSwitch,cAutonHotScale));
	else if (m_SV > 2.75)
		AddSequential(new cmdAuton5(cAutonHotSwitch,cAutonHotScale));
	else
		AddSequential(new cmdAuton1());
}


bool cmdAuton::IsFinished(){
		return false;
}

void cmdAuton::End(){

}


