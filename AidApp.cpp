/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////

#include <iomanip>
#include <iostream>
using namespace std;
#include "AidApp.h"
#include <string.h>
#include "AmaPerishable.h"




namespace sict{

	AidApp::AidApp(const char* filename)
	{
		strncpy(filename_, filename, 255);
		filename_[255] = 0;
		
		int i = 0;
		for (i = 0; i < MAX_NO_RECS; product_[i++]=nullptr);

		noOfProducts_ = 0;
		loadRecs();
	}

	AidApp::~AidApp(){
		int i = 0;
		for (i = 0; i < noOfProducts_; i++){
			delete product_[i];
		}
	}

	void AidApp::pause() const
	{
		cout << endl;
		cout << "Press Enter to continue..." << endl;
		cin.ignore(2000, '\n');
		while (cin.get() != '\n');	
	}

	int AidApp::menu()
	{
		int selId = -1;

		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quantity of purchased products" << endl;
		cout << "0- Exit program" << endl;
		cin >> selId;

		if (cin.fail() || (selId < 0) || (selId > 5)){
			selId = -1;
		}

		return selId;
	}

	void AidApp::loadRecs()
	{		
		datafile_.open(filename_, ios::in);
		if (datafile_.fail()){
			datafile_.clear();
			datafile_.close();

			datafile_.open(filename_, ios::out);
			datafile_.close();
		}
		else{	
			int readIndex = 0;	
			char ch;
			while (!datafile_.get(ch).fail()){
				datafile_.ignore();

				delete product_[readIndex];
				if (ch == 'P'){
					AmaPerishable* pitem = new AmaPerishable;
					pitem->load(datafile_);
					product_[readIndex] = pitem;
					readIndex++;
				}
				else if (ch == 'N'){
					AmaProduct* pitem = new AmaProduct;
					pitem->load(datafile_);
					product_[readIndex] = pitem;
					readIndex++;
				}				
			}
			noOfProducts_ += readIndex;
			datafile_.close();
		}		
	}

	void AidApp::saveRecs()
	{
	//	fstream file;
		datafile_.open(filename_, ios::out);

		int i = 0;
		for (i = 0; i < noOfProducts_; i++){
			product_[i]->store(datafile_);
		}
		datafile_.close();
	}

	void AidApp::listProducts() const
	{
		cout << endl;
		cout << setw(6) << left << " Row" << "|"
			<< setw(MAX_SKU_LEN+1) << left << " SKU" << "|"
			<< setw(20) << left << "  Product Name" << "|"
			<< setw(7) << left << setprecision(2) << fixed << "  Cost" << "|"
			<< setw(4) << left << " Qty" << "|"
			<< setw(10) << left << " Unit" << "|"
			<< setw(4) << left << "Need" << "|"
			<< setw(10) << left << " Expiry" << endl;


		cout << setw(7) << right << setfill('-') << "|"
			<< setw(MAX_SKU_LEN+2) << "|"
			<< setw(21)  << "|"
			<< setw(8)  << "|"
			<< setw(5)  << "|"
			<< setw(11) << "|"
			<< setw(5)  << "|"
			<< setw(11) << " " << endl << setfill(' ');

		int i = 0; 
		double totalCost = 0;
		
		for (i = 0; i < noOfProducts_; i++){
			cout << setw(5) << left << (i+1) << " | ";
			product_[i]->write(cout, true) << endl;
			
			if ((i+1)%10 == 0){
				pause();
			}
			totalCost += product_[i]->cost() * product_[i]->quantity();
		}

		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: " << fixed << setprecision(2) << "$" << totalCost << endl;
	}

	int AidApp::SearchProducts(const char* sku)const
	{
		int res = -1;
		int i = 0;
		for (i = 0; i < noOfProducts_; i++){
			if (*product_[i] == sku){
				res = i;
			}
		}
		return res;
	}

	void AidApp::addQty(const char* sku)
	{
		int matchId = SearchProducts(sku);
		if (matchId != -1){
			int addCnt = 0;
			cout << "Please enter the number of purchased items: ";
			cin >> addCnt;
			while (cin.fail()){
				cout << "Invalid quantity value!" << endl;
				cout << "Please enter the number of purchased items: ";
				cin >> addCnt;
			}

			if (addCnt <= (product_[matchId]->qtyNeeded() - product_[matchId]->quantity())){
				*product_[matchId] += addCnt;
			}
			else{
				int needCnt = product_[matchId]->qtyNeeded() - product_[matchId]->quantity();
				*product_[matchId] += needCnt;
				cout << "Too many items; only " << needCnt
					<<" is needed, please return the extra "<< addCnt - needCnt << " items." << endl;
			}
			saveRecs();
			cout << "Updated!" << endl;
		}
		else{
			cout << "Not found!" << endl;
		}

	}

	void AidApp::addProduct(bool isPerishable)
	{
		Product* pProd;
		if (isPerishable){
			pProd = new AmaPerishable;
		}
		else{
			pProd = new AmaProduct;
		}
		pProd->read(cin);
		if (!cin.fail()){
			product_[noOfProducts_] = pProd;
			noOfProducts_++;
		}
		saveRecs();
	}

	int AidApp::run()
	{
		char inputBuff[128];
		int selid = menu();
		int matchid = -1;

		while ((selid>=0) && (selid<=5)){
			switch (selid){
			case 0:
				cout << "Goodbye!!" << endl;
				selid = -1;
				break;
			case 1:
				listProducts();
				pause();
				selid = menu();
				break;
			case 2:
				cout << "Please enter the SKU:";
				cin >> inputBuff;
				matchid = SearchProducts(inputBuff);
				if (matchid == -1){
					cout << "Not found!" << endl;
				}
				else{
					product_[matchid]->write(cout, false);
				}
				selid = menu();
				break;
			case 3:
				addProduct(false);
				selid = menu();
				break;
			case 4:
				addProduct(true);
				selid = menu();
				break;
			case 5:
				cout << "Please enter the SKU:";
				cin >> inputBuff;
				addQty(inputBuff);
				selid = menu();
				break;
			default:
				cout << "===Invalid Selection, try again.===";				
				break;
			}
		}
		return 0;

	}
}