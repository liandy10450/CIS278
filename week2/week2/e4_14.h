/*	class e4_14
CIS278 Fall 17, HW2
Author: Andy Li
---
Program that will determine whether a department-store customer
has exceeded the credit limit on a charge account.
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double acctNum = 0;
	double begBal = 0;
	double totCharges = 0;
	double totCredits = 0;
	double creditLim;
	double newBal = 0;
	while (acctNum != -1) {
		cout << "Please enter account number(or -1 to quit): ";
		cin >> acctNum;

		if (acctNum != -1) {
			cout << "Please enter beginning balance: ";
			cin >> begBal;

			cout << "Please enter total charges: ";
			cin >> totCharges;

			cout << "Please enter total credits: ";
			cin >> totCredits;

			cout << "Please enter credit limit: ";
			cin >> creditLim;

			newBal = begBal + totCharges - totCredits;
			cout << "Your new balance is: " << setprecision(2) << fixed << newBal;
			cout << endl;
			//Check if new balance is greater than credit limit
			if (newBal > creditLim) {
				cout << "\nAccount number: " << setprecision(2) << fixed << acctNum;
				cout << "\nCredit Limit: " << setprecision(2) << fixed << creditLim;
				cout << "\nNew Balance: " << setprecision(2) << fixed << newBal;
				cout << "\nERROR: Credit limit exceeded!" << endl << endl;
			}

		}
	}
}