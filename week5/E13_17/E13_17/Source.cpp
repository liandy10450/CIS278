/*	class e13_17
CIS278 Fall 17, Week 5
Author: Andy Li
---
A program that uses a for statement to print a table of ASCII values 
for the characters in the ASCII character set from 33 to 126.  The program
should also print the decimal value, octal value, hexadecimal and character
value for each character
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main() {

	cout << "Printing characters in ASCII character set from 33 to 126..."<<endl;
	cout << "Decimal"<<"\t\t"<<"Octal"<<"\t\t"<<"Hex"<<"\t\t"<<"Character"<<endl;
	for (int i = 33; i < 126; i++) {
		std::cout << std::dec << i << "\t\t";
		std::cout << std::oct << i << "\t\t";
		std::cout << std::hex << i << "\t\t";
		cout <<(char)i<<endl;
	}
}//end main