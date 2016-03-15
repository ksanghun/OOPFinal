// Final Project Milestone 2
// Tester program
// File	MyFile.cpp
// Version 1.0
// Date	2016-3-14
// Author	Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2015/04/01           Preliminary release
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstring>
#include "MyFile.h"
using namespace std;
namespace sict{

  MyFile::MyFile(const char* fname){
    _text[0] = char(0);
    strcpy(_fname, fname);
  }
  fstream& MyFile::store(std::fstream& file, bool addNewLine)const{
    file.open(_fname, ios::app|ios::out);
    int i = 0;
    while (_text[i]){
      file << _text[i];
      i++;
    }
    file.close();
    return file;
  }
  fstream& MyFile::load(std::fstream& file){
    file.open(_fname, ios::in);
    int i=0;
    while (!file.fail()){
      _text[i++] = file.get();
    }
    file.clear();
    file.close();
    if(i > 0) i--;
    _text[i] = 0;
    return file;
  }
  ostream& MyFile::write(std::ostream& os, bool linear)const{
    for (int i = 0; _text[i]; i++){
      if (linear && _text[i] == '\n'){
        os << " ";
      }
      else{
        os << _text[i];
      }
    }
    return os;
  }
  istream& MyFile::read(std::istream& is){
    is.getline(_text, 9999, EOF);
    return is;
  }
  void MyFile::print(){
    write(cout, false);
    cout << endl;
  }
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf){
    return mf.write(ostr, true);
  }
  std::istream& operator>>(std::istream& istr, MyFile& mf){
    return mf.read(istr);
  }
}