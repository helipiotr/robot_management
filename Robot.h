#ifndef ROBOT_H


#define ROBOT_H
#include <vector>
#include <iostream>
#include "SafetyError.h"
#include <stdexcept>
#include "safetyMode.h"
#include "workMode.h"

//!  The main robot class
/*!
  This is a base class for different robot types. It implements some features.
*/
class Robot{
protected:
	//! Vector containing the motors 
	std::vector <double> motors_;
	//! Safety setting
	safetyMode safetyMode_;
public:
	//! Stops the robot.
	virtual void Stop()=0;
	
	//! Sets proper safety mode
	virtual void setSafetyMode(safetyMode inMode)=0;
	
	//! Sets motors
	/*!
		motorID starts from zero and identifies the motor
	*/
	void setMotor(int motorID, double value);
	
	//friend std::ostream& operator <<(std::ostream& os, const Robot& inRobot);
	
	
	//!  Robot serialisation
	/*!
		Returns: safety mode, number of motors, value of each motor
	*/
	std::ostream& get_state(std::ostream& os) const;
	
	//! Robot deserialisation
	std::istream& set_state(std::istream& is);  
	
};

#endif /* ROBOT_H */
