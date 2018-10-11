#define _SCL_SECURE_NO_WARNINGS

#include<string>
#include "Hardware.h"
using namespace std;


//Default constructor
Hardware::Hardware(int recNum, string tooNam, int tooQuan, double toolCos) {
	setRecordNum(recNum);
	setToolName(tooNam);
	setToolQuantity(tooQuan);
	setToolCost(toolCos);
}//end constructor
//setters
//function to set record number
void Hardware::setRecordNum(int num) {
	recordNum = num;
}
//function to set tool name
void Hardware::setToolName(string name) {
	int length = name.size();
	length = (length < 16 ? length : 15);
	name.copy(toolName, length);
	toolName[length] = '\0';//append null character to toolName
}
//function to set tool quantity
void Hardware::setToolQuantity(int num) {
	toolQuantity = num;
}
//function to set tool cost
void Hardware::setToolCost(double num) {
	toolCost = num;
}

//getters
int Hardware::getRecordNum()const {
	return recordNum;
}
//function to set tool name
string Hardware::getToolName()const {
	return toolName;
}
//function to set tool quantity
int Hardware::getToolQuantity()const {
	return toolQuantity;
}
//function to set tool cost
double Hardware::getToolCost()const {
	return toolCost;
}
