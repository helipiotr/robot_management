#include "MobileSens.h"


MobileSens::MobileSens(){
	//mockup values
	sensors_.push_back(1);
	sensors_.push_back(2);
	sensors_.push_back(3);
}

double MobileSens::readSensor(int sensorID, double & readValue){
	if (sensorID >= sensors_.size()){
		throw out_of_range("readSensor: The referred sensor does not exist");
	}
	
	readValue = sensors_[sensorID];
	return readValue;
}

