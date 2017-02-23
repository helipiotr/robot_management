#include "MobileRobot.h"
#include "SafetyError.h"
#include <stdexcept>

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
