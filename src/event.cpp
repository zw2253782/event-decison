//============================================================================
// Name        : event.cpp
// Author      : 
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
	cout<<eventObj.leftUp<<endl;


    if (eventObj.event == "turn") {

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
  jsonData["leftUp"] = 1.2;
  jsonData["event"] = "turn";

  Json::FastWriter fastWriter;
  std::string output = fastWriter.write(jsonData);
  return output;
}

/*class EventObj {

public:

  string event{""};
  double leftUp{0.0};
  double leftdown{0.0};
  double rightUp{0.0};
  double rightDown{0.0};

  int n{0};
  int index{0}; // 0 ... n - 1
  uint64_t parketeventStart{0};
  uint64_t parketeventEnd{0};
  string parketeventType{""};

};*/

EventObj fromJson(EventObj eventObj, string json) {
  Json::Value parsedFromString;
  Json::Reader reader;
  assert(reader.parse(json, parsedFromString));

  cout<<"inside"<<json<<endl;

  //parse json data and read more data
  eventObj.leftUp = parsedFromString["leftUp"].asDouble();
  eventObj.event = parsedFromString["event"].asString();
  //eventObj.leftUp = parsedFromString["leftUp"].asDouble();
  //eventObj.leftUp = parsedFromString["leftUp"].asDouble();
  cout<<"left"<<parsedFromString["leftUp"]<<eventObj.leftUp<<endl;

  return eventObj;
}
