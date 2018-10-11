/*	class e8_12
CIS278 Fall 17, Week 6
Author: Andy Li
---
A program that recreates the race of tortoise and hare.  Using random number
generation to develop a simulation of this event.
*/

#include<iostream>
using std::cout;
using std::endl;
#include<cstdlib>
#include<ctime>
#include<iomanip>
using std::setw;

const int RACE_END = 70;
//function prototypes
void moveTortoise(int * const);
void moveHare(int * const);
void printCurrentPositions(const int* const, const int* const);

int main() {
	//variables
	int tortoise = 1;
	int hare = 1;
	int timer = 0;
	int srand(time(0));

	//begin race message
	cout << "BANG !!!!!" << endl << "AND THEY'RE OFF !!!!!" << endl << endl;

	//while loops until contender wins
	while (tortoise < RACE_END && hare < RACE_END) {

		moveTortoise(&tortoise); //pass variable by reference
		moveHare(&hare);

		//Print positions
		printCurrentPositions( &tortoise, &hare);
		
		//update timer
		timer++;
	}//end while

	//Check who won
	if (tortoise > hare) {
		cout << "TORTOISE WINS!!!YAY!!!" << endl;
	}
	else if(hare > tortoise){
		cout << "YUCH" << endl;
	}
	else {
		cout << "It's a tie" << endl;
	}

}//end main

//functions
//moves tortoise
void moveTortoise(int * const tortoise) {	
	int move;
	//generate random number from 1-10
	move = rand() % 10 + 1;

	//checks number and choose move type
	//1-2 slip, 3-5 slow plod, 6-10 fast plod
	if (move >= 6) {//fast plod
		if (*tortoise > 67) {
			*tortoise = 70;
		}
		else {
			*tortoise += 3;
		}		
	}
	else if (move >= 3) {//slow plod
		*tortoise += 1;
	}
	else {//slip
		if (*tortoise < 6) {
			*tortoise = 1;
		}
		else {
			*tortoise -= 6;
		}		
	}
}//end moveTortoise

//moves hare
void moveHare(int * const hare) {
	int move;
	//generate random number from 1-10
	move = rand() % 10 + 1;

	//checks number and choose move type
	//1-2 small slip, 3-5 small hop, 6 big slip
	//7-8 big hop, 9-10 sleep
	if (move >= 9) {//sleep
		//do nothing
	}
	else if (move >= 7) {//big hop
		if (*hare > 61) {
			*hare = 70;
		}
		else {
			*hare += 9;
		}		
	}
	else if (move >= 6) {//Big slip
		if (*hare < 12) {
			*hare = 1;
		}
		else {
			*hare -= 12;
		}		
	}
	else if (move >= 3) {//small hop
		*hare += 1;
	}
	else {//small slip
		if (*hare < 2) {
			*hare = 1;
		}
		else {
			*hare -= 2;
		}		
	}
}

//print the current position of hare and tortoise
void printCurrentPositions(const int* const tortoise, const int* const hare) {
	for (int i = 1; i <= 70; i++) {
		if (i == *hare) {
			if (*hare == *tortoise) {
				cout << "OUCH!!!";
			}
			else {
				cout << "H";
			}
		}
		else if (i == *tortoise) {
			cout << "T";
		}
		else {
			cout << "=";
		}
		
	}
	cout << endl << "T = Tortoise" << endl << "H = Hare" << endl << endl;
}