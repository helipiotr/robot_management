#include "Manipulator.h"

Manipulator::Manipulator(){
	safetyMode_ = T1;
	workMode_ = distanceMode;
	motors_.resize(6,0);
}

void Manipulator::Stop(){
	workMode_ = distanceMode;
	int i;
	for (i = 0; i < 6 ; i++){
		motors_[i]=0;
	}
	safetyMode_ = T1;
}

void Manipulator::setSafetyMode(safetyMode inMode){
	safetyMode_ = inMode;

	int i;

	if (inMode == T1){
		for(i=0;i<motors_.size();i++){
			motors_[i]=0;
		}
		workMode_=distanceMode;
	}
}

void Manipulator::setWorkMode(workMode inWorkMode){
	workMode_ = inWorkMode;
}


std::ostream& Manipulator::get_state(std::ostream& os) const {

	os << static_cast<int>(safetyMode_ == T1) << std::endl;

	os << static_cast<int>(motors_.size()) << std::endl;

	int i; ;
	for (i = 0; i < motors_.size() ; i++){
		os << motors_[i] << std::endl;
	}

	os << static_cast<int>(workMode_ == forceMode) << std::endl;

	return os;
}

std::istream& Manipulator::set_state(std::istream& is){

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

	//! Determines whether the manipulator works in force or distance mode
	int var;
	is >> var;

	if(var){
		workMode_ = forceMode;
	}
	else
	{
		workMode_ = distanceMode;
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Manipulator& inManipulator)
{
	inManipulator.get_state(os);
	return os;
}

std::istream& operator>>(std::istream& is, Manipulator& inManipulator)
{
	inManipulator.set_state(is);
	return is;
}



