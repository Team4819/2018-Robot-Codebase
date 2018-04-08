/*
 * sysDrive.h
 *
 *  Created on: Feb 18, 2018
 *      Author: Terry
 */

#ifndef SRC_SUBSYSTEMS_SYSDRIVE_H_
#define SRC_SUBSYSTEMS_SYSDRIVE_H_

#include <Spark.h>
#include <PWMTalonSRX.h>
#include <SpeedControllerGroup.h>
#include <Commands/Subsystem.h>
#include <Drive/MecanumDrive.h>
#include <Encoder.h>
#include <AHRS.h>

#include "../RobotMap.h"

namespace frc{
class Joystick;
}

class sysDrive : public frc::Subsystem{
public:
	sysDrive();

	void InitDefaultCommand() override;

	void Log();

	void Drive(double x, double y, double z, double gyroAngle);

	frc::Encoder g_leftFrontEncoder{2,3};//,Encoder::EncodingType::k1X};
	frc::Encoder g_rightFrontEncoder{4,5};//Encoder::EncodingType::k1X};
	frc::Encoder g_leftRearEncoder{6,7};//Encoder::EncodingType::k1X};
	frc::Encoder g_rightRearEncoder{8,9};//Encoder::EncodingType::k1X};

	AHRS *m_gyro = new AHRS(SerialPort::Port::kUSB);

private:

	frc::PWMTalonSRX m_LFCim{g_iLFCimID};
	frc::PWMTalonSRX m_LFMini{g_iLFMiniID};
	frc::SpeedControllerGroup m_scgLF{m_LFCim, m_LFMini};

	frc::PWMTalonSRX m_LRCim{g_iLRCimID};
	frc::PWMTalonSRX m_LRMini{g_iLRMiniID};
	frc::SpeedControllerGroup m_scgLR{m_LRCim, m_LRMini};

	frc::PWMTalonSRX m_RFCim{g_iRFCimID};
	frc::PWMTalonSRX m_RFMini{g_iRFMiniID};
	frc::SpeedControllerGroup m_scgRF{m_RFCim, m_RFMini};

	frc::PWMTalonSRX m_RRCim{g_iRRCimID};
	frc::PWMTalonSRX m_RRMini{g_iRRMiniID};
	frc::SpeedControllerGroup m_scgRR{m_RRCim, m_RRMini};

	frc::MecanumDrive m_robotDrive{m_scgLF, m_scgLR, m_scgRF, m_scgRR};



};


#endif /* SRC_SUBSYSTEMS_SYSDRIVE_H_ */
