// Final Project Milestone 4 
// Product Tester program
// File	ms4_prof.cpp
// Version 1.0
// Date	2016-3-17
// Author	Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2016-03-17		       Preliminary release
/////////////////////////////////////////////////////////////////

#include <iomanip>
#include <cstdlib>
#include "Product.h"
#ifdef TAB
# undef TAB
#endif
#define TAB '\t'
using namespace std;
namespace sict{
  class SItem :public Product{
  public:
    SItem(const char* theSku, const char * theName):Product(theSku, theName){}
    SItem(){}
    virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const{
      if (!isEmpty()){
        file.open("ms4.txt", ios::out|ios::app);
        file << sku() << TAB << name() << TAB << quantity() << TAB << qtyNeeded() << TAB
          << int(taxed()) << TAB << price() << endl;
        file.clear();
        file.close();
      }
      return file;
    }
    virtual std::fstream& load(std::fstream& file){
      file.open("ms4.txt", ios::in);
      char buf[2000];
      double dbuf;
      int ibuf;
      file >> buf;
      sku(buf);
      file >> buf;
      name(buf);
      file >> ibuf;
      quantity(ibuf);
      file >> ibuf;
      qtyNeeded(ibuf);
      file >> ibuf;
      taxed(bool(ibuf));
      file >> dbuf;
      price(dbuf);
      file.clear();
      file.close();
      return file;
    }
    virtual std::ostream& write(std::ostream& os, bool linear)const{
      return isEmpty() ? os : (os << sku() << ": " << name() << ", qty: " 
        << quantity() << ", qtyNeeded:" << qtyNeeded() 
        <<", Cost: " << fixed << setprecision(2) << cost());
    }
    virtual std::istream& read(std::istream& is){
      char buf[2000];
      double dbuf;
      int ibuf;
      cout << "Sku: ";
      is >> buf;
      sku(buf);
      cout << "Name (no spaces): ";
      is >> buf;
      name(buf);
      cout << "Qty: ";
      is >> ibuf;
      quantity(ibuf);
      cout << "Qty Needed: ";
      is >> ibuf;
      qtyNeeded(ibuf);
      cout << "Is taxed? (1/0): ";
      is >> ibuf;
      taxed(bool(ibuf));
      cout << "Price: ";
      is >> dbuf;
      price(dbuf);
      return is;
    }
  };
}
void dumpFile(fstream& f){
  f.open("ms4.txt", ios::in);
  char ch;
  while (!f.get(ch).fail()){
    cout.put(ch);
  }
  f.clear();
  f.close();
}
using namespace sict;
void test(){
  double res, val = 0.0;
  fstream F("ms4.txt", ios::out);
  F.close();
  SItem S;
  SItem T;
  SItem U;
  cout << "Enter Product info: " << endl;
  cin >> S;
  SItem V = S;
  S.store(F);
  T.load(F);
  cout << "T: (store, load)" << endl;
  cout << T << endl;
  cout << "S: " << endl;
  cout << S << endl;
  cout << "V(S): " << endl;
  cout << V << endl;
  cout << "U=T & op= :" << endl;
  U = T;
  cout << U << endl;
  cout << "Operator == :" << endl;
  cout << "op== is " << (T == "1234" ? "OK" : "NOT OK") << endl;
  cout << "op+=: " << endl;
  U += 10;
  cout << U << endl;
  cout << "op+=double : " << endl;
  res = val += U;
  cout << res << "=" << val <<endl;
}
int main(){
  fstream F("ms4.txt", ios::out);
  F.close();
  SItem S;
  SItem U("4321", "Rice");
  cout << "Empty Prouduct:" << endl << S << endl;
  cout << "U(\"4321\", \"Rice\"):" << endl << U << endl;

  cout << "Please enter the following information:" << endl;
  cout << "Sku: 1234" << endl;
  cout << "Name(no spaces) : Blanket" << endl;
  cout << "Qty : 12" << endl;
  cout << "Qty Needed : 23" << endl;
  cout << "Is taxed ? (1 / 0) : 1" << endl;
  cout << "Price : 12.34" << endl;
  test();
  cout << "Please enter the following information:" << endl;
  cout << "Sku: 1234" << endl;
  cout << "Name(no spaces) : Jacket" << endl;
  cout << "Qty : 12" << endl;
  cout << "Qty Needed : 23" << endl;
  cout << "Is taxed ? (1 / 0) : 0" << endl;
  cout << "Price : 12.34" << endl;
  test();
  dumpFile(F);
  cout << "----The End" << endl;
  return 0;
}
