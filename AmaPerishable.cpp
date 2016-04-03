/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////

#include <iostream>
#include "AmaPerishable.h"

using namespace std;
namespace sict{

	AmaPerishable::AmaPerishable() : AmaProduct('P')
	{
		
	}

	const Date& AmaPerishable::expiry()const
	{
		return expiry_;
	}
	void AmaPerishable::expiry(const Date &value)
	{
		expiry_ = value;
	}


	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const
	{
		AmaProduct::store(file, false) << ",";
		expiry_.write(file);
		if (addNewLine){
			file << endl;
		}
		return file;
	}
	fstream& AmaPerishable::load(fstream& file)
	{
		AmaProduct::load(file);
		expiry_.read(file);
		file.ignore(1);		

		return file;
	}
	ostream& AmaPerishable::write(ostream& os, bool linear)const
	{
		AmaProduct::write(os, linear);
		if (err_.isClear() && AmaProduct::isEmpty()==false){
			if (linear){
				expiry_.write(os);
			}
			else{
				os << endl << "Expiry date: ";
				expiry_.write(os);
			}
		}

		return os;
	}
	istream& AmaPerishable::read(istream& is)
	{
		Date tmpDate;
		AmaProduct::read(is);
		if (err_.isClear()){
			cout << "Expiry date (YYYY/MM/DD): ";
			tmpDate.read(is);
		}

		switch (tmpDate.errCode()){
		case NO_ERROR:
			expiry_ = tmpDate;
			break;
		case CIN_FAILED :
			err_ = "Invalid Date Entry";
			is.setstate(ios::failbit);
			break;
		case YEAR_ERROR:
			err_ = "Invalid Year in Date Entry";
			is.setstate(ios::failbit);
			break;
		case MON_ERROR:
			err_ = "Invalid Month in Date Entry";
			is.setstate(ios::failbit);
			break;
		case DAY_ERROR:
			err_ = "Invalid Day in Date Entry";
			is.setstate(ios::failbit);
			break;			
		}
		return is;
	}
}
