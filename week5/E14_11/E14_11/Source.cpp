/*	class e14_11
CIS278 Fall 17, Week 5
Author: Andy Li
---
A program that keeps invetory of a hardware store, keeping track
of different tools and how many of each.  Initializes the random-access
file hardware.dat to 100 empty records, lets you delete a record for a tool
no longer have and update any information in the file.
*/

#include<iostream>
#include<iomanip>
#include<fstream>//file stream
#include<cstdlib>
#include<string>
#include "Hardware.h" //Hardware class definition
using namespace std;

//function prototypes
int enterChoice();
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const Hardware &);
int getRecord(const char*const);
void listTools(fstream&);//reads and lists tools from random file

enum Choices {PRINT = 1, UPDATE, NEW, DELETE, END};

int main() {
	int recNum = 0;
	string toolName = "";
	int quantity = 0;
	double cost = 0.0;

	fstream outHardware("hardware.dat", ios::in | ios::out|ios::binary);

	//exit if cannot open
	if (!outHardware) {
		cerr << "File could not be opened."<<endl;
		exit(1);
	}//end if

	Hardware blankHardware;//constructor with default values

	//create 100 blanks
	for (int i = 0; i < 100; i++) {
		outHardware.write(reinterpret_cast<const char*>(&blankHardware),
			sizeof(Hardware));
	}

	int choice;//store user choice

	//enable user to specify action
	while ((choice = enterChoice()) != END) {
		switch (choice) {
		case PRINT:
			listTools(outHardware);
			break;
		case UPDATE:
			updateRecord(outHardware);
			break;
		case NEW:
			newRecord(outHardware);
			break;
		case DELETE:
			deleteRecord(outHardware);
			break;
		default:
			cerr << "Incorrect choice" << endl;
			break;
		}//end switch

		outHardware.clear();
	}
}//end main

//enable user to input choice
int enterChoice() {
	// display available options
	cout << "\nEnter your choice" << endl
		 << "1 - lists all your tools" << endl
		 << "2 - update a hardware" << endl
		 << "3 - add a new hardware" << endl
		 << "4 - delete a hardware" << endl
		 << "5 - end program\n? ";
	
		 int menuChoice;
	 cin >> menuChoice; // input menu selection from user
	 return menuChoice;//translated by ENUMS
}
//lists tools
void listTools(fstream &readFromFile) {
	/*
	ifstream inHardware("Hardware.dat", ios::in || ios::binary);

	//exit if ifstream cannot open open
	if (!inHardware) {
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	cout << left << setw(10) << "Record#" << setw(16)
		<< "Tool name" << setw(11) << "Quantity" << left
		<< setw(10) << right << "Cost" << endl;

	Hardware hardware; //create record
	
	//Read first record from file
	inHardware.read(reinterpret_cast<char *>(&hardware),
		sizeof(Hardware));

	//Read all records 
	while ( inHardware && !inHardware.eof() ) {
		//display record
		if (hardware.getRecordNum() != 0) {
			outputLine(cout, hardware);

			//read next from file
			inHardware.read(reinterpret_cast<char*>(&hardware),
				sizeof(Hardware));
		}
	}//end while
	*/
	//create text file
	ofstream outPrintFile("print.txt", ios::out);

	//exit if ofstream cannot create
	if (!outPrintFile) {
		cerr << "File could not be created." << endl;
		exit(1);
	}//end if

	outPrintFile << left << setw(10) << "Record#" << setw(16)
		<< "Tool name" << setw(11) << "Quantity" << left
		<< setw(10) << right << "Cost" << endl;

	//set file position pointer ot beginning of readFromFile
	readFromFile.seekg(0);

	//read first record from file
	Hardware hardware;
	readFromFile.read(reinterpret_cast<char*>(&hardware),
		sizeof(Hardware));
	//copy all records from record file into text file
	while (!readFromFile.eof()) {
		//write single record to text file
		if (hardware.getRecordNum() != 0) {
			outputLine(outPrintFile, hardware);
		}
		//read next record
		readFromFile.read( reinterpret_cast< char*>(&hardware),
			sizeof(Hardware));
	}
}//end list tools
void outputLine(ostream &output,const Hardware &record) {

	output << left << setw(10) << record.getRecordNum()
		<< setw(16) << record.getToolName()
		<< setw(11) << record.getToolQuantity()
		<< setw(10) << setprecision(2) << right << fixed
		<< showpoint << record.getToolCost() << endl;
}//end outputLine

//updates record
void updateRecord(fstream &updateFile) {
	string str;
	int num;
	double cost;

	//obtain record number
	int recordNumber = getRecord("Enter account to update" );

	//move file-position pointer to correct record in file
	updateFile.seekg((recordNumber - 1) * sizeof(Hardware));

	//read first record from file
	Hardware hardware;
	updateFile.read(reinterpret_cast<char*>(&hardware),
		sizeof(Hardware));

	//update record
	if (hardware.getRecordNum() != 0) {
		outputLine(cout, hardware);

		//request user to specify transaction
		cout << "\nEnter int 1.tool name, 2.quantity or 3.cost: ";
		int subject;
		cin >> subject;
		
		switch (subject)
		{
		case 1:
			cout << "Enter new tool name:\n? ";
			cin >> str;
			hardware.setToolName(str);
			break;
		case 2:
			cout << "Enter new quantity:\n? ";
			cin >> num;
			hardware.setToolQuantity(num);
			break;
		case 3:
			cout << "Enter new cost:\n? ";
			cin >> cost;
			hardware.setToolCost(cost);
			break;
		default:
			cerr << "invalid input" << endl;
			break;
		}
	}

}//end update
//create new record 
void newRecord(fstream &insertInFile) {
	//obtain number of record to create
	int recordNum = getRecord("Enter new record number" );

	//move file-position pointer to correct record in file
	insertInFile.seekg((recordNum - 1) * sizeof(Hardware));

	//read record from file
	Hardware hardware;
	insertInFile.read(reinterpret_cast<char*>(&hardware),
		sizeof(Hardware));

	//create record if does not exist
	if (hardware.getRecordNum() == 0) {

		string toolName;
		int quantity;
		double cost;

		//user enters toolName, quantity and cost
		cout << "Tool name\n? ";
		cin >> ws;//absorb whitespace
		getline(cin, toolName);
		//cin.getline (toolName, sizeof toolName);
		cout << "Quantity\n? ";
		cin >> quantity;
		cout << "Cost\n? ";
		cin >> cost;

		//set hardware values
		hardware.setRecordNum(recordNum);
		hardware.setToolName(toolName);
		hardware.setToolQuantity(quantity);
		hardware.setToolCost(cost);

		//move file position pointer to correct record in file
		insertInFile.seekp((recordNum - 1) * sizeof(Hardware));

		//insert record in file
		insertInFile.write(reinterpret_cast<const char*>(&hardware),
			sizeof(Hardware));
	}
	else//num already exist
	{
		cerr << "Record#" << recordNum
			<< " already contains information." << endl;
	}
}//end newRecord
//deletes record
void deleteRecord(fstream &deleteFromFile) {
	//obtain number of record to delete
	int recordNum = getRecord("Enter record to delete");	
	
	//move file-position pointer to correct record in file
	deleteFromFile.seekg((recordNum - 1) * sizeof(Hardware));

	//read record from file
	Hardware hardware;
	deleteFromFile.read(reinterpret_cast<char*>(&hardware),
		sizeof(Hardware));

	//delete if exist
	if (hardware.getRecordNum() != 0) {
		Hardware blankHardware;//create blank

		//move file position to correct record in file
		deleteFromFile.seekp((recordNum - 1) *
			sizeof(Hardware));

		//replace existing record with blank
		deleteFromFile.write(
			reinterpret_cast<const char*>(&blankHardware),
			sizeof(Hardware));

		cout << "Record #" << recordNum << "deleted.\n";
	}//end if
	else {
		cerr << "Record #" << recordNum << " is empty.\n";
	}
}//end deleteRecord
//obtain record number value from user
int getRecord(const char* const prompt) {
	int recordNum;

	//obtain record num value
	do {
		cout << prompt << " (1-100): ";
		cin >> recordNum;

	} while (recordNum < 1 || recordNum > 100);

	return recordNum;
}//end get record
