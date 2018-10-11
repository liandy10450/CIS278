//Hardware.h
//Hardware class definition separate file from main
#ifndef HARDWARE_H
#define HARDWARE_H



#include<iostream>
#include<string>
using namespace std;

class Hardware
{
public:
	Hardware(int = 0, string = "", int = 0, double = 0.0); //constructor sets record num, tool name, quantity and cost
	//setters
	void setRecordNum(int);
	void setToolName(string);
	void setToolQuantity(int);
	void setToolCost(double);
	//getters
	int getRecordNum()const;
	string getToolName()const;
	int getToolQuantity()const;
	double getToolCost()const;
private:
	int recordNum;
	char toolName[ 16];
	int  toolQuantity;
	double toolCost;
};//end class hardware

#endif // !HARDWARE_H