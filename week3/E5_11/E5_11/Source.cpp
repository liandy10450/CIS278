/*	class e5_11
CIS278 Fall 17, HW2
Author: Andy Li
---
Program that uses a for statement to find the smallest of several integers.  Assume that the first value read
specifies the number of values remaining
*/
#include <iostream>
using namespace std;

int main() {
	int smallest = 0;
	int size = 0;
	int num = 0;

	cout << "Please enter the number of integers being compared: ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> num;

		if (i == 0) {
			smallest = num;//sets first number to smallest
		}
		else if (num < smallest) {
			smallest = num;
		}
	}

	cout << "The smallest is: "<<smallest<<endl;
	return 0;
}