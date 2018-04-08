/*
 * RobotMap.h
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#ifndef SRC_ROBOTMAP_H_
#define SRC_ROBOTMAP_H_

	const int g_iWheelSize=8;
	const float g_dDistancePerTick = (g_iWheelSize  * M_PI) / 360.0;


	const int g_iLFCimID=0;
	const int g_iLFMiniID=1;
	const int g_iRFCimID=2;
	const int g_iRFMiniID=3;
	const int g_iLRCimID=4;
	const int g_iLRMiniID=5;
	const int g_iRRCimID=6;
	const int g_iRRMiniID=7;

	const int g_iElevatorMCID=8;
	const int g_iClimberMCID=9;

	const int g_iGrabberSolenoidID = 0;

	const int g_iLimitStart = 1;
	const int g_iLimitALLDown = 0;
	const int g_iLimitSwitchPos = 2;


	const double m_Auto1 = 4.75;
	const double m_Auto2 = 4.25;
	const double m_Auto3 = 3.75;
	const double m_Auto4 = 3.25;
	const double m_Auto5 = 2.75;
	const double m_Auto6 = 2.25;
	const double m_Auto7 = 1.75;
	const double m_Auto8 = 1.25;
	const double m_Auto9 = .75;
	const double m_Auto10 = .25;



#endif /* SRC_ROBOTMAP_H_ */
