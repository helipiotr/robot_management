Release: Robot.o main.o Manipulator.o MobileRobot.o MobileSens.o RobotConsole.o
	g++  -Wall -std=c++11 Robot.o main.o Manipulator.o MobileRobot.o MobileSens.o RobotConsole.o -o Release
main.o: main.cc
	g++ -std=c++11 -c main.cc
Robot.o: Robot.cc Robot.h
	g++ -std=c++11 -c Robot.cc
Manipulator.o: Manipulator.cc Manipulator.h
	g++ -std=c++11 -c Manipulator.cc
SafetyError.o: SafetyError.cc SafetyError.h
	g++ -std=c++11 -c SafetyError.cc
MobileRobot.o: MobileRobot.cc MobileRobot.h
	g++ -std=c++11 -c MobileRobot.cc
MobileSens.o: MobileSens.cc MobileSens.h
	g++ -std=c++11 -c MobileSens.cc
RobotConsole.o: RobotConsole.cc RobotConsole.h
	g++ -std=c++11 -c RobotConsole.cc
