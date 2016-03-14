// Final Project Milestone 1
// Student error handling tester program
// Version 1.0
// Date	03/03/2016
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "Date.h"
#include "general.h"
using namespace std;
using namespace sict;
int main(){
	int ret = 0;
	bool ok = true;

	if (ok){
		Date A;
		cout << "Testing error handling in read funciton;" << endl;
		cout << "cin faliure detection, " << endl;
		cout << "Please enter the following string \"abcd\": ";
		cin >> A;
		if (A.errCode() == CIN_FAILED){
			cout << "passed!" << endl;
		}
		else {
			cout << "Your read function does not check cin.fail() after entry," << endl
				<< "or it did not set _readErrorCode to CIN_FAILED" << endl;
			ok = false;
		}
		cin.clear();
		cin.ignore(2000, '\n');
	}
	if (ok){
		Date A;
		cout << "Year validation, " << endl;
		cout << "Please enter the following string \"10/1/1\": ";
		cin >> A;
		cout << "You entered: " << A << endl;
		if (A.errCode() == YEAR_ERROR){
			cout << "passed!" << endl;
		}
		else {
			cout << "Your read function does not check the year entry limits after entry," << endl
				<< "or it did not set _readErrorCode to YEAR_ERROR" << endl;
			ok = false;
		}
		cin.ignore(2000, '\n');
	}
	if (ok){
		Date A;
		cout << "Month validation, " << endl;
		cout << "Please enter the following string \"2000/13/1\": ";
		cin >> A;
		cout << "You entered: " << A << endl;
		if (A.errCode() == MON_ERROR){
			cout << "Passed" << endl;
		}
		else {
			cout << "Your read function does not check the month entry limits after entry," << endl
				<< "or it did not set _readErrorCode to MON_ERROR" << endl;
			ok = false;
		}
		cin.ignore(2000, '\n');
	}
	if (ok){
		Date A;
		cout << "Day validation, " << endl;
		cout << "Please enter the following string \"2000/1/50\": ";
		cin >> A;
		cout << "You entered: " << A << endl;
		if (A.errCode() == DAY_ERROR){
			cout << "Passed!" << endl;
		}
		else {
			cout << "Your read function does not check the day entry limits after entry," << endl
				<< "or it did not set _readErrorCode to DAY_ERROR" << endl;
			ok = false;
		}
		cin.ignore(2000, '\n');
	}
	if (ok){
		Date A;
		cout << "Day validation, leap year:" << endl;
		cout << "Please enter the following string \"2016/2/29\": ";
		cin >> A;
		cout << "You entered: " << A << endl;
		if (A.errCode() == DAY_ERROR){
			cout << "Your read function does not check the day entry limits using mday()" << endl;
			ok = false;
		}
		else {
			cout << "passed!" << endl;
		}
		cin.ignore(2000, '\n');
	}
	if (ok){
		cout << "You passed all error handling tests." << endl << endl
			<< " If you have started with test no 1 and came down to here, " << endl
			<< " you can now upload your files to matrix and submit milestone 1." << endl;
	}
	else{
		cout << "You did not pass all the tests, keep working on your project!" << endl;
		ret = 1;
	}

	return ret;
}
