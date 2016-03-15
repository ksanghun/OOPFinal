// Final Project Milestone 2
// Tester program
// File	MyFile.h
// Version 1.0
// Date	2016-3-14
// Author	Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__
#include "Streamable.h"
namespace sict{
  class MyFile : public Streamable {
    char _fname[256];
    char _text[10000];
  public:
    MyFile(const char* fname);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
    void print();
  };
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf);
  std::istream& operator>>(std::istream& istr, MyFile& mf);
}
#endif