#ifndef MANIPULATOR_H
#define MANIPULATOR_H


#include <iostream>
#include "Robot.h"


//!  Class of an industrial manipulator
/*!
  This class implements a 6-axis industrial manipulator,
  * as well some virtual functions from the Robot class.
*/

class Manipulator: public Robot{
	//! Work mode setting
	workMode workMode_;
public:
	//! A constructor.
    /*!
      It keeps the motors at zero position
    */
	Manipulator();
	
	//! Stops the robot.
    /*!
      Sets work mode to distance, position to zero and safety mode to T1
    */
	virtual void Stop();
	
	//! Sets the work mode
	void setWorkMode(workMode inWorkMode);
	
	//! Sets the safety mode
	virtual void setSafetyMode(safetyMode inMode);
	
	//! Insertion operator
	friend std::ostream& operator << (std::ostream& os, const Manipulator& inManipulator);

	//! Extraction operator
	friend std::istream& operator >> (std::istream& is, Manipulator& inManipulator);
	
};

#endif /* MANIPULATOR_H */
