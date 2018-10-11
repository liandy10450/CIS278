/*	class e5_17
CIS278 Fall 17, Week 3
Author: Andy Li
---
A program that reads a series of pairs of numbers then uses
switch staqtements to determine the retail price of each product.
*/

#include<iostream>
#include <iomanip>
using namespace std;

int main() {
	int prodNum = 0;
	int quantSold = 0;

	double total = 0;
	do{
		//prompt uster for product number and quantity sold
		cout << "What is the product number(or enter 0 to terminate): ";
		cin >> prodNum;
		if (prodNum == 0) {
			break;
		}
		cout << "How many of product " << prodNum << " was sold: ";
		cin >> quantSold;

		switch (prodNum) {
		case 1:
			total = total + 2.98*quantSold;
			break;
		case 2:
			total = total + 4.50*quantSold;
			break;
		case 3:
			total = total + 9.98*quantSold;
			break;
		case 4:
			total = total + 4.49*quantSold;
			break;
		case 5:
			total = total + 6.87*quantSold;
			break;
		default:
			cout << "Please enter 1-5"<<endl;
			break;
		}
		cout ;
		cout << "Total is: "<<setprecision(2) <<fixed <<total<<endl;
	} while ((prodNum != 0));
	
}