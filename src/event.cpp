//============================================================================
// Name        : event.cpp
// Author      : wei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "headers.h"


using namespace std;
EventObj fromJson(EventObj eventObj, string json);
void start(string json);
string CreateJson();
void checkTurn(EventObj eventObj);
void checkBrake(EventObj eventObj);
void checkLaneChange(EventObj eventObj);

int main() {

	string eventjson = CreateJson();
	cout<<"great"<<eventjson<<endl;
	start(eventjson);
	return 0;
}


void start(string json){

	EventObj eventObj;
	eventObj = fromJson(eventObj,json);
	cout<<eventObj.event<<endl;
	cout<<eventObj.upperleft_h<<endl;


	/*Accel. / Deceleration
Steering Angle
Turning Radius
Head Pose
Turning Signal*/
    if (eventObj.event == "turn") {
    	cout<<"event turn"<<endl;
        double score = 100;
        int direction = 0;//left = -1, straight = 0, right 1
        checkTurn(eventObj);
        if(eventObj.direction = 0){
        	score = 0;
        }

    } else if (eventObj.event == "hardbrake") {
    	cout<<"event hardbrake"<<endl;

    } else if (eventObj.event == "lanechange"){
    	cout<<"event lanechange"<<endl;

    } else {
        cout<<"Unknown event:"<<endl;
    }

}


string CreateJson() {
  Json::Value jsonData;
  jsonData["leftUp"] = 18;
  jsonData["event"] = "turn";

  Json::FastWriter fastWriter;
  std::string output = fastWriter.write(jsonData);
  return output;
}


EventObj fromJson(EventObj eventObj, string json) {
  Json::Value parsedFromString;
  Json::Reader reader;
  assert(reader.parse(json, parsedFromString));

  cout<<"inside"<<json<<endl;

  //parse json data and read more data
  eventObj.upperleft_h = parsedFromString["leftUp"].asDouble();
  eventObj.event = parsedFromString["event"].asString();
  //eventObj.leftUp = parsedFromString["leftUp"].asDouble();
  //eventObj.leftUp = parsedFromString["leftUp"].asDouble();
  cout<<"left"<<parsedFromString["leftUp"]<<eventObj.upperleft_h<<endl;

  return eventObj;
}

void checkTurn(EventObj eventObj){

	if (eventObj.box_num>0) {
	}
}

void checkBrake(EventObj eventObj){

}
void checkLaneChange(EventObj eventObj){

}


/*
 * Vehicle Speed
Accel. / Deceleration
Steering Angle
Turning Radius
Head Pose
Turning Signal


Excessive of Jerk
Front Vehicle Distance
Traffic Control Signal
Pedestrian / Cyclist
Head Pose
Front Vehicle Distance
Rear Vehicle Distance
Turning Signal
Maneuver Duration
Head Pose
 * */


