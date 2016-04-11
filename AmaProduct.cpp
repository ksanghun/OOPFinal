/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string.h>
#include "AmaProduct.h"

using namespace std;
namespace sict{

	AmaProduct::AmaProduct(char fileTag)
	{
		fileTag_ = fileTag;
	}
	const char* AmaProduct::unit() const
	{
		return unit_;
	}
	void AmaProduct::unit(const char* value)
	{
		if (value){
			strncpy(unit_, value, 10);
			unit_[10] = 0;
		}
	}

	fstream& AmaProduct::store(fstream& file, bool addNewLine)const
	{
		file << fileTag_ << "," << sku() << "," << name() << "," <<
			price() << "," << taxed() << "," <<
			quantity() << "," << unit() << "," << qtyNeeded();
		if (addNewLine){
			file << endl;
		}
		return file;
	}
	fstream& AmaProduct::load(fstream& file)
	{
		char readBuff[128];

		file.getline(readBuff, 128, ',');
		sku(readBuff);
		file.getline(readBuff, 128, ',');
		name(readBuff);
		file.getline(readBuff, 128, ',');
		price(atof(readBuff));
		file.getline(readBuff, 128, ',');
		taxed(bool(atoi(readBuff)));
		file.getline(readBuff, 128, ',');
		quantity(atoi(readBuff));
		file.getline(readBuff, 128, ',');
		unit(readBuff);
		file.getline(readBuff, 128, '\n');
		qtyNeeded(atoi(readBuff));


		return file;
	}
	ostream& AmaProduct::write(ostream& os, bool linear)const
	{
		if (!err_.isClear()){
			os << err_.message();
		}
		else{			
			if (linear){
				os << setw(MAX_SKU_LEN) << left << sku() << "|"
					<< setw(20) <<left << name() << "|"
					<< setw(7) << right << setprecision(2) << fixed << cost() << "|"
					<< setw(4) << right << quantity() << "|"
					<< setw(10) << left << unit() << "|"
					<< setw(4) << right << qtyNeeded() << "|";
			}
			else{
				os << "Sku: " << sku() << endl
					<< "Name: " << name() << endl
					<< "Price: " << price() << endl;
				if (taxed()){
					os << "Price after tax: " << cost() << endl;
				}
				else{
					os << "Price after tax: N/A" << endl;
				}					
				os	<< "Quantity On Hand: " << quantity() <<" "<< unit() << endl
					<< "Quantity Needed: " << qtyNeeded();
			}			
		}

		return os;
	}
	istream& AmaProduct::read(istream& is)
	{ 
		err_.clear();
		char	inputBuff[128];
		int		inputInt = 0;
		double	inputDouble;

		_input<char*>(is, "Sku: ", inputBuff);
		sku(inputBuff);
		_input<char*>(is, "Name: ", inputBuff);
		name(inputBuff);
		_input<char*>(is, "Unit: ", inputBuff);
		unit(inputBuff);
		_input<char*>(is, "Taxed? (y/n): ", inputBuff);
		

		if (inputBuff[0] == 'Y' || inputBuff[0] == 'y' || 
			inputBuff[0] == 'N' || inputBuff[0] == 'n'){
			is.clear();
			if (inputBuff[0] == 'Y' || inputBuff[0] == 'y'){
				taxed(true);
			}
			else{
				taxed(false);
			}

			if (_input<double&>(is, "Price: ", inputDouble)){
				price(inputDouble);
				if (_input<int&>(is, "Quantity On hand: ", inputInt)){
					quantity(inputInt);
					if (_input<int&>(is, "Quantity Needed: ", inputInt)){
						qtyNeeded(inputInt);
					}
					else{
						err_ = "Invalid Quantity Needed Entry";
						is.setstate(ios::failbit);
					}
				}
				else{
					err_ = "Invalid Quantity Entry";
					is.setstate(ios::failbit);
				}
			}
			else{
				err_ = "Invalid Price Entry";
				is.setstate(ios::failbit);
			}	
		}
		else{
			cout << "Price: ";
			err_ = "Only (Y)es or (N)o are acceptable";
			is.setstate(ios::failbit);
		}
		return is;
	}


}