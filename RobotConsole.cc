#include "RobotConsole.h"
#include <string>
#include <iostream>
#include <sstream>

#include "MobileRobot.h"
#include "MobileSens.h"
#include "Manipulator.h"

//using namespace std;

void RobotConsole::getInput(){
	int a;
	
	for (std::string line; 
	run_ && std::cout << "APP > " && std::getline(std::cin, line); )
    {	
        if (!line.empty())
			parseLine(line);
    }
}


void RobotConsole::parseLine(std::string & inLine){
	std::string firstWord;
	
	std::stringstream ss(inLine);
	ss >> firstWord;
	if (firstWord == "exit"){
		std::cout << "exitting" << std::endl;
		run_ = 0;
	}else if (firstWord == "add"){
		cout << "Adding... " << endl;
		addRobot(ss);
	}else if (firstWord == "show"){
		cout << "Requested robot table is:" << endl;
		showRobots();
	}	
	else{
		std::cout << "Wrong command" << std::endl;
	}
}

void RobotConsole::showRobots(){
	int i;
	
	//START WORKING HERE NOT COMPLETE
	//std::stringstream ss;
	//ss << *robotContainer_[0];//->get_state(ss);
	//std::cout<<ss<<endl;
		
	for( i = 0 ; i < robotNames_.size() ; ++i){
		std::cout << i << "\t"<< robotNames_[i] << endl;
		//std::cout << robotContainer_ << endl;
	}
	
}

void RobotConsole::addRobot(std::stringstream & ss){
	std::string robotType;
	ss >> robotType;
	if (robotType == "MobileRobot" ){
		robotContainer_.push_back ( new MobileRobot );
		robotNames_.push_back( robotType );
		std::cout 
			<< "A mobile robot has been successfully added" 
			<< std::endl;
	}
	else if ( robotType == "MobileSens" ){
		robotContainer_.push_back ( new MobileRobot );
		robotNames_.push_back( robotType );
		std::cout 
			<<"A mobile robot with sensors has been successfully added" 
			<< std::endl;
	}
	else if ( robotType == "Manipulator" ){
		robotContainer_.push_back ( new Manipulator );
		robotNames_.push_back( robotType );
		std::cout
			<<"A manipulator has been successfully added" 
			<< std::endl;
	} else{
		std::cout << "Unsupported / wrong robot type" << std::endl;
	}
}

RobotConsole::~RobotConsole(){
	int i;
	
	//Stopping the robots
	for ( i = 0; i< robotContainer_.size() ; ++i){
		robotContainer_[i]->Stop();	
	}
	
	//Deleting memory allocated to robots
	for ( i = 0; i< robotContainer_.size() ; ++i){
		delete robotContainer_[i];	
	}
}
