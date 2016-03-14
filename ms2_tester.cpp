// Final Project Milestone 2
// File	ms1_tester.cpp
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
#include "ErrorMessage.h"
using namespace std;
using namespace sict;
int main(){
  ErrorMessage T("Testing Error Message");
  ErrorMessage e;
  cout << T << endl << e << endl << "isClear(): " << (e.isClear() ? "Passed!" : "failed!") << endl;
  for (int i = 0; i < 1000000; i++){
    e = "Some error message that is really long long  long  long  long  long  long  long"
        " long  long  long  long  long  long  long  long  long  long  long  long  long";
  }
  cout << e << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
  e.message("Short Message");
  cout << e << endl << e.message() << endl << "isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
  e.clear();
  cout << e << endl << "isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl;
  return 0;
}