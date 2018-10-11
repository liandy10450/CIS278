/*	class e6_57
CIS278 Fall 17, Week 4
Author: Andy Li
---
A program that will help elementary students learn multiplication.
Uses rand function to produce two positive one-digit integers.
*/
#include<iostream>
#include<iomanip>
using namespace std;
int genQuest(int&, int&);
int main() {
	int numOne = 0;
	int numTwo = 0;

	int anw = 1;
	int sol = 0;

	while (anw != 0) {
		//randomizes numbers
		sol = genQuest(numOne, numTwo);

		//Check if anw is correct
		do {
			cout << "How much is " << numOne << " times " << numTwo << "? (input 0 to terminate)";
			cin >> anw;

			if (anw == 0) {
				break;
			}
			else if (anw == sol) {
				cout << "Very good!" << endl;
			}
			else {
				cout << "No.  Please try again. " << endl;
			}

		} while (anw != sol);
	}
	
	
}

int genQuest(int& numOne, int& numTwo) {
	numOne = rand() % 9 + 1;
	numTwo = rand() % 9 + 1;

	return numOne * numTwo;
}