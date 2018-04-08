/*
 * cmdAutoWAIT.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: USER
 */
#include "cmdAutoWAIT.h"

cmdAutoWAIT::cmdAutoWAIT(double dWaitTime)
: frc::Command("cmdAutoWAIT"){
	m_WaitTime =dWaitTime;
}

void cmdAutoWAIT::Initialize(){
	SetTimeout(m_WaitTime);
}

void cmdAutoWAIT::Execute(){}

bool cmdAutoWAIT::IsFinished(){
	return IsTimedOut();
}

void cmdAutoWAIT::End(){
	m_WaitTime = 0;
}

