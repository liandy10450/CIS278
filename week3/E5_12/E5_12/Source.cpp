/*	class e5_12
CIS278 Fall 17, HW2
Author: Andy Li
---
Program that uses for statement to calculate and print
the product of the odd integers from 1 to 15.
*/
#include <iostream>
using namespace std;
int main() {
	int product = 1;
	for (int i = 1; i < 16; i++) {
		if (i % 2 != 0) {
			product = product * i;
		}
	}
	cout << "The product of odd integers from 1 to 15 is: "<<product<<endl;

	return 0;
}