/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////


#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
namespace sict{

	class Date{

		int year_;
		int mon_;
		int day_;
		int readErrorCode_;

	private:
		int value()const;
		void errCode(int errorCode);
		void setEmpty();
		void validateDate();

	public:
		Date();
		Date(int year, int mon, int day);
		~Date();

		void setValue(int year, int mon, int day);	

		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;

		int errCode() const;
		bool bad() const;

		int mdays()const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};

	//Non-member IO operator overloads: 
	std::ostream& operator<<(std::ostream& ostr, const Date& D);
	std::istream& operator>>(std::istream& istr, Date& D);

}
#endif