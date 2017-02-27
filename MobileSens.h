#ifndef MOBILE_SENS_H
#define MOBILE_SENS_H

#include "MobileRobot.h"

//!  The mobile robot with sensors class
/*!
  This is a four-wheeled robot with sensors and simple control
*/

class MobileSens: public MobileRobot{
protected:
	vector<double> sensors_;
public:

	//! MobileSens constructor
	MobileSens();

	//! Reads data from sensor
	double readSensor(int sensorID, double & readValue);

	//! Insertion operator
	//friend std::ostream& operator << (std::ostream& os, const MobileSens& inMobileSens);

	//! Extraction operator
	//friend std::istream& operator >> (std::istream& is, MobileSens& inMobileSens);
};

#endif /* MOBILE_SENS_H */
