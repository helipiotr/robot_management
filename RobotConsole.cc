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

	ifstream helpStream;

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
	}else if(firstWord == "save"){
        saveRobots();
	}
	else if(firstWord == "setMotor"){
        parseSetMotor(ss);
	}
	else if(firstWord == "setSafety"){
        parseSafetyMode(ss);
	}
	else if(firstWord == "load"){
        loadRobots();
	}
	else if(firstWord == "help"){
        helpStream.open("helpfile.txt");
        if ( helpStream.is_open() ){
            std::cout << helpStream.rdbuf() << endl;
        }else{
            std::cout << "Cannot open the helpfile" << endl;
        }
	}
	else
	{
		std::cout << "Wrong command, type 'help' for reference" << std::endl;
	}
}

void RobotConsole::showRobots(){
	//! Iterator
	int i;

	for( i = 0 ; i < robotNames_.size() ; ++i){
		std::cout << "ID: "<< i << "\t Type:"<< robotNames_[i] << endl;
		std::cout << "Status: [safety mode | number of motors | motors configuration]" << endl;
		robotContainer_[i]->get_state(std::cout);
	}

}

void RobotConsole::addRobot(std::stringstream & ss){
    //! Variable reading the robot type
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
    //! Iterator
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

void RobotConsole::saveRobots(){
    //! Output stream
    ofstream outStream;
    //! Iterator
    int i;

    //Opening a file
    outStream.open("saved_robots");

    //Writing the number of robots
    outStream << robotNames_.size() << endl;

    //Writing present robot types
	for( i = 0 ; i < robotNames_.size() ; ++i){
        outStream << robotNames_[i] << endl;
	}

    for( i = 0 ; i < robotNames_.size() ; ++i){
		robotContainer_[i]->get_state(outStream);
	}

    outStream.close();
}

void RobotConsole::loadRobots(){
    //! Input stream
    ifstream inStream;

    try{
        inStream.open("saved_robots");

        if ( !inStream.is_open() )
            throw runtime_error("cannot open the specified file");

    }
    catch(std::runtime_error &e){
        cerr << e.what() << std::endl;
    }

    //! Iterator
    int i;

    int robotsNumber;

    string robotBuff;

    inStream >> robotsNumber;

    for ( i = 0 ; i < robotsNumber ; ++i){

        inStream >> robotBuff;
        robotNames_.push_back(robotBuff);

        if ( robotBuff == "Manipulator")
        {
            robotContainer_.push_back(new Manipulator);
        }
        else if (robotBuff == "MobileRobot")
        {
            robotContainer_.push_back(new MobileRobot);
        }
        else if (robotBuff == "MobileSens")
        {
            robotContainer_.push_back(new MobileSens);
        }
    }

    for (i = 0 ; i < robotsNumber ; ++i){
        robotContainer_[i]->set_state(inStream);
    }

    std::cout << "Robots successfully loaded" << endl ;

}



void RobotConsole::parseSetMotor(std::stringstream & ss){
    int robID;
    int motorID;
    double motorVal;
    ss >> robID >> motorID >> motorVal;
    //std::cout << robID << endl << motorID << endl << motorVal << endl;
    try{
        robotContainer_[robID]->setMotor(motorID, motorVal);
    }
    catch(const SafetyError &e){
		cerr << e.what() << std::endl;
	}
	catch( std::out_of_range &e ){
		cerr << e.what() << std::endl;
	}
}

void RobotConsole::parseSafetyMode(std::stringstream & ss){
    std::string secondWord;
    int robID;
    ss >> robID;
    ss >> secondWord;
    if(secondWord == "T1"){
        try{
            if(robID > robotContainer_.size()){
                throw out_of_range("The referred motor does not exist");
            }
            robotContainer_[robID]->setSafetyMode(T1);
        }
        catch(std::out_of_range &e){
            cerr << e.what() << std::endl;
        }
    }
    else if (secondWord == "T2"){
        try{
            if(robID > robotContainer_.size()){
                throw out_of_range("The referred motor does not exist");
            }
            robotContainer_[robID]->setSafetyMode(T2);
        }
        catch(std::out_of_range &e){
            cerr << e.what() << std::endl;
        }
     }

}
/*
void RobotConsole::displaySensors(std::stringstream & ss){
    int robID;
    int sensorID;
    double readValue;
    MobileSens MScopy;
    ss >> robID >> sensorID;
    try{
        if(robID > robotContainer_.size())
            throw out_of_range("The reffered robot does not exist");
    }
    catch(std::out_of_range &e){
        cerr << e.what() << std::endl;
    }

    try{
        if(robotNames_[robID] != "MobileSens")
            throw out_of_range("Invalid robot type");
        //MScopy = *robotContainer_[robID];
        //std::cout << (robotContainer_)->readValue(sensorID,readValue) << endl;
    }
    catch(std::out_of_range &e){
        cerr << e.what() << std::endl;
    }

}
*/





