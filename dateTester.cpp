// Final Project Milestone 1
// Date Tester program
// File	dateTester.cpp
// Version 1.1
// Date	2016/02/23
// Author	Fardad Soleimanloo
// Description
// This is the simple program to get you started
// and is not a tester program for submission
//
// 1.1 changed oop244 namespace to sict
//
//
/////////////////////////////////////////////////////////////////

#include "date.h"
#include "general.h"
#include <iostream>
using namespace sict;
using namespace std;

// A fool proof Date entry from console
Date getDate();

int main(){
  Date
    D1,   // value to be recieved from console
    D2(2017,10, 20);
  cout << "Please enter a date to be compared to 2017/10/20."<<endl <<
          "YYYY/MM/DD > ";
  D1= getDate();
  cout <<"Your Entry: "<< D1 << endl;
  cout <<"Set by program to 2017/10/20: "<< D2 << endl;
  cout << "All the following statements must be correct: " << endl;
  if (D1 > D2){
    cout << D1 << " > " << D2 << endl;
  }
  else{
    cout << D1 << " <= " << D2 << endl;
  }
  if (D1 < D2){
    cout << D1 << " < " << D2 << endl;
  }
  else{
    cout << D1 << " >= " << D2 << endl;
  }
  if (D1 <= D2){
    cout << D1 << " <= " << D2 << endl;
  }
  else{
    cout << D1 << " > " << D2 << endl;
  }
  if (D1 >= D2){
    cout << D1 << " >= " << D2 << endl;
  }
  else{
    cout << D1 << " < " << D2 << endl;
  }
  if (D1 == D2){
    cout << D1 << " == " << D2 << endl;
  }
  else{
    cout << D1 << " != " << D2 << endl;
  }
  if (D1 != D2){
    cout << D1 << " != " << D2 << endl;
  }
  else{
    cout << D1 << " == " << D2 << endl;
  }
  return 0;
}

Date getDate(){
  Date D;
  do{
    cin >> D;      // get D from console
    switch (D.errCode())    {
    case CIN_FAILED:
      cin.clear();
      cout << "Invlid date Entry";
      break;
    case YEAR_ERROR:
      cout << "Invlid year; " << MIN_YEAR << "<= year <= " << MAX_YEAR;
      break;
    case MON_ERROR:
      cout << "Invlid month, 1<=Mon<=12";
      break;
    case DAY_ERROR:
      cout << "Invlid Day, 1<=Day<=" << D.mdays();
    }
    cin.ignore(2000, '\n');
  } while (D.bad() && cout << ", Please try again > ");  // if D is invalid, print ", Please try again > " and loop
  return D;
}
