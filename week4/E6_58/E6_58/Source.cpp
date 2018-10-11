/*	class e6_58
CIS278 Fall 17, Week 4
Author: Andy Li
---
Modified version of 6_57 that displays various comments
*/

#include<iostream>
using namespace std;

int genQuest(int&, int&);//function prototype

int main() {
	int numOne = 0;
	int numTwo = 0;

	int anw = 1;
	int sol = 0;

	int chooseComment;

	while (anw != 0) {
		//randomizes numbers
		sol = genQuest(numOne, numTwo);

		//Check if anw is correct
		do {
			cout << "How much is " << numOne << " times " << numTwo << "? (input 0 to terminate): ";
			cin >> anw;

			if (anw == 0) {
				break;
			}
			else if (anw == sol) {
				chooseComment = rand() % 1 + 4;

				switch (chooseComment) {
				case 1:
					cout << "Very good!" << endl;
					break;
				case 2:
					cout << "Excellent!" << endl;
					break;
				case 3:
					cout << "Nice work!" << endl;
					break;
				case 4:
					cout << "Keep up the good work!" << endl;
					break;
				}
			}
			else {
				chooseComment = rand() % 1 + 4;

				switch (chooseComment) {
				case 1:
					cout << "No. Please try gain." << endl;
					break;
				case 2:
					cout << "Wrong.  Try once more." << endl;
					break;
				case 3:
					cout << "Don't give up!" << endl;
					break;
				case 4:
					cout << "No. Keep trying." << endl;
					break;
				}
			}

		} while (anw != sol);
	}


}

int genQuest(int& numOne, int& numTwo) {
	numOne = rand() % 9 + 1;
	numTwo = rand() % 9 + 1;

	return numOne * numTwo;
}