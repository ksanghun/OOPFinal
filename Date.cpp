/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////

#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"


#define MAX_INBUFFER_SIZE 64

namespace sict{

	Date::Date()
	{
		setEmpty();
	}

	Date::Date(int year, int mon, int day)
	{
		setValue(year, mon, day);
		readErrorCode_ = NO_ERROR;
	}

	Date::~Date()
	{

	}

	void Date::setEmpty()
	{
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}

	void Date::setValue(int year, int mon, int day)
	{
		year_ = year; 
		mon_ = mon;
		day_ = day;			
	}

	void Date::validateDate()
	{
		if ((year_ < MIN_YEAR) || (year_ > MAX_YEAR)){
			readErrorCode_ = YEAR_ERROR;
		}

		if ((mon_<=0) || (mon_ >= 13))
		{
			readErrorCode_ = MON_ERROR;	
		}
		else{
			if ((day_ < 0) || (day_ > mdays())){
				readErrorCode_ = DAY_ERROR;
			}
		}	
	}

	void Date::errCode(int errorCode)
	{
		readErrorCode_ = errorCode;
	}
	
	int Date::value()const{
		return year_ * 372 + mon_ * 31 + day_;
	}

	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}

	// Member-operators //
	bool Date::operator==(const Date& D)const
	{
		return (value() == D.value());
	}
	bool Date::operator!=(const Date& D)const
	{
		return (value() != D.value());
	}
	bool Date::operator<(const Date& D)const
	{
		return (value() < D.value());
	}
	bool Date::operator>(const Date& D)const
	{
		return (value() > D.value());
	}
	bool Date::operator<=(const Date& D)const
	{
		return (value() <= D.value());

	}
	bool Date::operator>=(const Date& D)const
	{
		return (value() >= D.value());
	}

	int Date::errCode() const
	{
		return readErrorCode_;
	}
	bool Date::bad() const
	{
		return (readErrorCode_ != 0);
	}

	//member IO functoin : 
	istream& Date::read(istream& istr)
	{		
		char ch;
		istr >> year_ >> ch >> mon_ >> ch >> day_;
		if (cin.fail()){
			readErrorCode_ = CIN_FAILED;
		}	
		else{
			validateDate();
		}
		return istr;
	}
	ostream& Date::write(ostream& ostr)const
	{
		ostr << year_ << '/' << setw(2) << setfill('-') << mon_ 
					  << '/' << setw(2) << day_ << setfill(' ');
		return ostr;
	}

	//Non-member IO operator overloads: 
	ostream& operator<<(ostream& ostr, const Date& D)
	{
		return D.write(ostr);
	}
	istream& operator>>(istream& istr, Date& D)
	{
		return D.read(istr);
	}
}
