#include "MobileRobot.h"
#include "SafetyError.h"
#include <stdexcept>
#include <iostream>

MobileRobot::MobileRobot(){
	safetyMode_ = T1;
	motors_.resize(4,0);
}

void MobileRobot::Stop(){
	safetyMode_ = T1;
	motors_.resize(4,0);
}

void MobileRobot::setSafetyMode(safetyMode inMode){
	safetyMode_ = inMode;

	int i;

	if (inMode == T1){
		for(i=0;i<motors_.size();i++){
			motors_[i]=0;
		}
	}
}
std::ostream& MobileRobot::get_state(std::ostream& os) const {

	os << static_cast<int>(safetyMode_ == T1) << std::endl;

	os << static_cast<int>(motors_.size()) << std::endl;

	int i; ;
	for (i = 0; i < motors_.size() ; i++){
		os << motors_[i] << std::endl;
	}

	//std::cout << os << endl;
	//std::cout << motors_.size() << endl;

	return os;
}

std::istream& MobileRobot::set_state(std::istream& is){

	//! Variable storing dafety mode
	int safetyVar;
	//! Number of motors
	int motorsNum;
	int i;

	is >> safetyVar;

	if(safetyVar){
		safetyMode_ = T1;
	}
	else{
		safetyMode_ = T2;
	}

	is >> motorsNum;

	//! De-serialised motor value
	double readMotorVal;

	for(i=0; i<motorsNum ; ++i){
		is >> readMotorVal;
		motors_[i]=readMotorVal;
	}

	return is;
}


std::ostream& operator<<(std::ostream& os, const MobileRobot& inMobileRobot)
{
	inMobileRobot.get_state(os);

	return os;
}

std::istream& operator>>(std::istream& is, MobileRobot& inMobileRobot)
{
	inMobileRobot.set_state(is);

	return is;
}
