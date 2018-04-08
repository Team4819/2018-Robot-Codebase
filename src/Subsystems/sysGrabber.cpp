/*
 * sysGrabber.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: E01388
 */

#include <Joystick.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Solenoid.h>
#include "../Commands/cmdGrabberUser.h"
#include "sysGrabber.h"

sysGrabber::sysGrabber()
: frc::Subsystem("sysGrabber"){

	g_fGrabberOpen=false;
}

void sysGrabber::InitDefaultCommand() {
	SetDefaultCommand (new cmdGrabberUser());
}

void sysGrabber::OpenGrabber(){
	m_GrabberSolenoid.Set(true);
	g_fGrabberOpen = true;
}

void sysGrabber::CloseGrabber(){
	m_GrabberSolenoid.Set(false);
	g_fGrabberOpen = false;
}


