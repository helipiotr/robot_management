/*! \mainpage Robot classes example project
 *
 * \section intro_sec Introduction
 *
 * The main aim of this project is to introduce concept of inheritance
 * in writing c++ classes. There are three connected classes.
 * Additionally, this project introduces exception mechanisms.
 *
 * \section install_sec Installation
 * Just use the makefile
 *
 */

#include <iostream>
#include <fstream>
#include "Robot.h"
#include "Manipulator.h"
#include "MobileRobot.h"
#include "MobileSens.h"
#include "RobotConsole.h"

using namespace std;

int main(){

	/*
	ofstream maniFile;
	maniFile.open("ziemniak.dat");
	Manipulator our_manipulator;
	maniFile << our_manipulator;
	maniFile.close();
	ifstream inputFile;
	inputFile.open("ziemniak.dat");
	inputFile >> our_manipulator ;
	inputFile.close();
	*/

    /*
	vector <Robot*> ourRobots;
	int i;

	Manipulator ourManipulator;
	MobileRobot ourMobileRobot;
	MobileSens ourMobileSens;

	ourManipulator.setSafetyMode( T2 );
	ourManipulator.setWorkMode( forceMode );

	try{
		//testing the setMotor exception
		ourManipulator.setMotor(6, 35);
	}
	catch(const SafetyError &e){
		cerr << e.what() << std::endl;
	}
	catch( std::out_of_range &e ){
		cerr << e.what() << std::endl;
	}


	ourMobileRobot.setSafetyMode(T2);

	try{
		//this should work properly
		for(i=0;i<4;i++){
			ourMobileRobot.setMotor(i, 35);
		}
	}
	catch(const SafetyError &e){
		cerr << e.what() << std::endl;
	}

	catch( std::out_of_range &e ){
		cerr << e.what() << std::endl;
	}


	double reading;
	try{
		//this should work
		ourMobileSens.readSensor(0, reading);
	}
	catch(std::out_of_range &e){
		cerr << e.what() << std::endl;
	}

	ourRobots.push_back( & ourManipulator );
	ourRobots.push_back( & ourMobileRobot );
	ourRobots.push_back( & ourMobileSens );

	for (i=0; i< ourRobots.size() ; ++i)
		ourRobots[i]->Stop();

    */

	//ostream os;
	//ourMobileRobot.get_state(cout);
	//cout << os << endl;
	//cout << ourMobileRobot;

	//Manipulator secondManipulator;

	//std::cout << secondManipulator << endl;

	//std::cout << (*ourRobots[0]).print() << endl;


	//beginning console interface

	RobotConsole ourConsole;

	ourConsole.getInput();


	cout << "Console closed " << endl;

	return 0;
}
