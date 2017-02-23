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

std::ostream& operator<<(std::ostream& os, const Manipulator& inManipulator)
{
	inManipulator.get_state(os);
	
	os << static_cast<int>(inManipulator.workMode_ == forceMode) << std::endl;
	
	return os;
}

std::istream& operator>>(std::istream& is, Manipulator& inManipulator)
{	
	inManipulator.set_state(is);
	
	//! Determines whether the manipulator works in force or distance mode
	int var;
	is >> var;
	
	if(var){
		inManipulator.workMode_ = forceMode;
	}
	else
	{
		inManipulator.workMode_ = distanceMode;
	}

	return is;
}



