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
void CheckTurn(EventObj eventObj);
void CheckBrake(EventObj eventObj);
void CheckLaneChange(EventObj eventObj);

int main() {

	string eventjson = CreateJson();
	cout<<"create"<<eventjson<<endl;
	start(eventjson);
	return 0;
}


void start(string json){

	EventObj eventObj;
	eventObj = fromJson(eventObj,json);
	cout<<eventObj.event<<endl;
	cout<<eventObj.upperleft_h<<endl;

        int limitedSpeed = 35;


	/*Accel. / Deceleration
Steering Angle
Turning Radius
Head Pose
Turning Signal*/
    if (eventObj.event == "turn") {
    	cout<<"event turn"<<endl;
        double score = 0;
        //int direction = 0;//left = -1, straight = 0, right 1
        CheckTurn(eventObj);
        double turningRadius = 0;
        if(eventObj.direction = 0 || eventObj.headpose == 0 || isTurningSignal == false){
        	score -= 100;
        } else if (eventObj.speed > limitedSpeed*1.1){
                score -= 50;
        } else if (eventObj.accel == true && eventObj.speed >15){
                score -= 20;
        } else if (eventObj.decel == true && eventObj.speed < 15){
                score += 20;
        } else{
        }

    } else if (eventObj.event == "hardbrake") {
    	cout<<"event hardbrake"<<endl;
        double score = 0;
        if(CheckBrake(eventObj)){
               return "reasonable";
        } else{
               return "harmful";
        }

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

void CheckTurn(EventObj eventObj){

	if (eventObj.box_num>0) {
	}
}


void savePreviousObj(EventObj eventObj){
     EventObj preEventObj = eventObj;
}


void CheckBrake(EventObj eventObj){
        int objSize = 0;
        int carize = 111;
	if (eventObj.box_num = 0) {//object in front 
             //check what obj, check distance, check if it is moveing
            objSize = abs((eventObj.bottomright_h - eventObj.upperleft_h)*(eventObj.bottomright_v - eventObj.upperleft_v));
        }else if (eventObj) {

	} else{
             return false;
        }
}
void CheckLaneChange(EventObj eventObj){

}


/*
 * Vehicle Speed
Accel. / Deceleration
Steering Angle
Turning Radius //由转弯半径R与外轮转角之间的关系是 R=L/Sinθ。+a 可知，转弯半径仅与外轮转角θ。、轴距L、主销到外轮轮辙中心线距离a有关，所以根据车辆的参数应该能直接算出
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


