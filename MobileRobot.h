#ifndef MOBILE_ROBOT_H
#define MOBILE_ROBOT_H

#include "Robot.h"
#include "workMode.h"

//!  The mobile robot class
/*!
  This is a four-wheeled robot with simple control
*/
class MobileRobot: public Robot{
public:
	//! MobileRobot constructor
	MobileRobot();
	//! Stops the robot.
	virtual void Stop();
	//! Sets proper safety mode
	virtual void setSafetyMode(safetyMode inMode);
	
	//! Insertion operator
	friend std::ostream& operator << (std::ostream& os, const MobileRobot& inMobileRobot);

	//! Extraction operator
	friend std::istream& operator >> (std::istream& is, MobileRobot& inMobileRobot);
	
};

#endif /* MOBILE_ROBOT_H */
