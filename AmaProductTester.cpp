// Final Project Milestone 5
// AmaProduct Tester program
// Version 1.0
// Date 2016-03-23
// Author Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
      
/////////////////////////////////////////////////////////////////
#include "AmaProduct.h"
using namespace sict;
using namespace std;
void piv(const char* sku, const char* name, const char* unit = "", char Tx = '\0',
         const char* price = "",const char* qty = "", const char* qtyNd = "", 
          const char* date = ""){
  cout
    << "Enter the following: " << endl
    << "Sku: " << sku << endl
    << "Name: " << name << endl
    << "Unit: " << unit << endl;
  if (Tx) cout << "Taxed: " << Tx << endl;
  if (price[0]) cout << "Price: " << price << endl;
  if (qty[0]) cout << "Quantity on hand: " << qty << endl;
  if (qtyNd[0]) cout << "Quantity needed: " << qtyNd << endl;
  if ( date[0]) cout << "Expiry date: " << date << endl;
  cout << endl;
}
void dumpFile(const char* fname){
  ifstream f(fname);
  char ch;
  while (!f.get(ch).fail()){
    cout.put(ch);
  }
  f.clear();
  f.close();
}
void _pause(){
  cout << "****press enter to continue...";
  cin.ignore(1000, '\n');
}

int main(){
  fstream prdfile("amaPrd.txt", ios::out);
  AmaProduct amaPrd;
  bool ok = true;
  int i;
  cout << "--AmaProduct test:" << endl;
  cout << "----Taxed validation test:" << endl;
  piv("abc", "abc", "abc", 'a');
  cin >> amaPrd;
  if (cin.fail()){
    cin.clear();
    cin.ignore(2000, '\n');
    cout << "Passed!" << endl
      << "Message shoule be:  Only (Y)es or (N)o are acceptable" << endl
      << "Your Error message: " << amaPrd << endl;
  }
  else{
    ok = false;
    cout << "Taxed validation failed" << endl;
  }
  _pause();
  if (ok){
    cout << "----Price validation test:" << endl;
    piv("abc", "abc", "abc", 'y', "abc");
    cin >> amaPrd;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed!" << endl
        << "Message shoule be:  Invalid Price Entry" << endl
        << "Your Error message: " << amaPrd << endl;
    }
    else{
      ok = false;
      cout << "Price validation failed" << endl;
    }
    _pause();
  }
  if (ok){
    cout << "----Quantity validation test:" << endl;
    piv("abc", "abc", "abc", 'y', "10", "abc");
    cin >> amaPrd;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed!" << endl
        << "Message shoule be:  Invalid Quantity Entry" << endl
        << "Your Error message: " << amaPrd << endl;
    }
    else{
      ok = false;
      cout << "Quantity validaton failed" << endl;
    }
  }
  _pause();
  if (ok){
    cout << "----Quantity Needed validation test:" << endl;
    piv("abc", "abc", "abc", 'y', "10", "10", "abc");
    cin >> amaPrd;
    if (cin.fail()){
      cin.clear();
      cin.ignore(2000, '\n');
      cout << "Passed!" << endl
        << "Message shoule be:  Invalid Quantity Needed Entry" << endl
        << "Your Error message: " << amaPrd << endl;
    }
    else{
      ok = false;
      cout << "Quantity Needed validaton failed" << endl;
    }
  }
  _pause();
  if (ok){
    cout << "----Display test, the output of the Program and yours must match:" << endl;
    piv("1234", "box", "kg", 'y', "123.45", "1", "5");
    cin >> amaPrd;
    cin.ignore(1000, '\n');
    cout << "--Linear------------" << endl;
    cout << "Program: 1234   |Box                 | 139.50|   1|kg        |   5|" << endl;
    cout << "  Yours: " << amaPrd << endl;
    cout << "--Form Display------" << endl;
    cout << "--Program: " << endl;
    cout << "Sku: 1234" << endl;
    cout << "Name : box" << endl;
    cout << "Price : 123.45" << endl;
    cout << "Price after tax : 139.50" << endl;
    cout << "Quantity On Hand : 1 kgs" << endl;
    cout << "Quantity Needed : 5" << endl;
    cout << "--Yours: " << endl;
    amaPrd.write(cout, false) << endl;
  }
  _pause();
  if (ok){
    cout << "----Storage and loading test, the output of the Program and yours must match:" << endl;
    AmaProduct tprd;
    amaPrd.store(prdfile);
    amaPrd.store(prdfile);
    prdfile.close();
    cout << "--Store AmaProduct, program: " << endl
      << "N,1234,box,123.45,1,1,kg,5" << endl
      << "N,1234,box,123.45,1,1,kg,5" << endl;
    cout << "--Store AmaProduct, yours: " << endl;
    dumpFile("amaPrd.txt");
    cout << "--Load AmaProduct: " << endl;
    prdfile.open("amaPrd.txt", ios::in);
    prdfile.ignore(2);
    tprd.load(prdfile);
    cout << "Program: 1234   |box                 | 139.50|   1|kg        |   5|" << endl;
    cout << "  Yours: " << tprd << endl;
    prdfile.clear();
    prdfile.close();
  }
  return 0;
}