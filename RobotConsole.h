#ifndef ROBOT_CONSOLE_H
#define ROBOT_CONSOLE_H

#include <iostream>
#include <string>
#include "Robot.h"
#include <vector>
#include <fstream>
#include <stdexcept>

//!  Robot console class
/*!
* Class describing the robot console, used to add and manage robots in
* the system.
*/

class RobotConsole{
	//! Variable definig whether the console should be active
	bool run_;
	//! Vector containing robots in the system
	std::vector <Robot*> robotContainer_;
	//! Vector describing robots in the system
	std::vector <string> robotNames_;
public:
	//! Main constructor - running with false is possible but fairly pointless
	RobotConsole(bool run = true): run_(run) {};

	//! function collecting data from the console
	void getInput();

	//! Main function determining what to do with the input
	void parseLine(std::string & inLine);

	//! Function adding a robot
	void addRobot(std::stringstream & ss);

	//! Shows robots and their state
	void showRobots();

	//!Saves to disk
	void saveRobots();

	//! Retrives past state from disk to the programme
	/*!
		* Please remeber that IDs of the robots are changed if the current list is not empty
	*/
	void loadRobots();

	//!Sets the motors
	void parseSetMotor(std::stringstream & ss);

	//!Sets the appropriate safety mode
	void parseSafetyMode(std::stringstream & ss);

	/*void displaySensors(std::stringstream & ss);*/

	//! Destructor stopping and deleting approriate robot representations
	/*!
		* Note to self: no, you don't delete the robots physically,
		* just its virtual representation
	*/
	~RobotConsole();
};


#endif /* ROBOT_CONSOLE_H*/
