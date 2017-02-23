#include "Robot.h"

//std::ostream& operator <<(std::ostream& os, const Robot& inRobot){}

std::ostream& Robot::get_state(std::ostream& os) const {
	
	os << static_cast<int>(safetyMode_ == T1) << std::endl;
	
	os << static_cast<int>(motors_.size()) << std::endl;

	int i; ;
	for (i = 0; i < motors_.size() ; i++){
		os << motors_[i] << std::endl;
	}
	
	return os;
}

std::istream& Robot::set_state(std::istream& is){
	
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
		motors_.push_back(readMotorVal);
	}

	return is;
}

void Robot::setMotor(int motorID, double value){
	
	if(safetyMode_ == T1){
		throw SafetyError("setMotor: You have to set safety mode to T2 to start");
	}
	
	if(motorID >= motors_.size() ){
		throw out_of_range("setMotor: The referred motor does not exist");
	}
	
	motors_[motorID] = value;
	
}
