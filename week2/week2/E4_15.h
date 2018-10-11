/*	class e4_15
CIS278 Fall 17, HW2
Author: Andy Li
---
Program that uses a while statement to input each saleperson's
gross sales for last week and calculates and displays that saleperson's earnings.

*/
#include <iostream>
#include <iomanip>
using namespace std;
class E4_15 {
	double sales = 0;
	double salary = 0;
	while (sales != -1) {
		cout << "Enter sales in dollars (-1 to end): ";
		cin >> sales;

		//calculate salary
		salary = 200 + (.09*sales);
		cout << "Salary is: " << setprecision(2) << fixed << salary << endl << endl;
	};
}