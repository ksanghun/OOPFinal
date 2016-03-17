/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////

#include <iomanip>
#include <iostream>
using namespace std;
#include "Product.h"


namespace sict{

	Product::Product()
	{
		setEmpty();
	}

	Product::Product(const char* csku, const char* cname, double dprice, int iqtyNeeded, bool bisTaxed) :
		name_(nullptr), taxed_(bisTaxed),
		quantity_(0), qtyNeeded_(iqtyNeeded), price_(dprice){

		sku(csku);
		name(cname);			
	}

	Product::Product(Product& P)
	{
		
	}


	Product::~Product()
	{

	}

	void Product::setValue(const Product& P)
	{
		sku(P.sku());
		name(P.name());
		price(P.price());
		quantity(P.quantity());
		qtyNeeded(P.qtyNeeded());
		taxed(P.taxed());
	}

	Product& Product::operator = (const Product& P)
	{
		setValue(P);
		return *this;
	}

	void Product::setEmpty()
	{
		sku_[0] = 0;
		name_ = nullptr;
		price_ = 0.0;
		taxed_ = 0;
		quantity_= 0;
		qtyNeeded_=0;
	}

	void Product::clear()
	{
		delete[] name_;
		name_ = nullptr;
	}

	bool Product::isEmpty() const
	{
		return true;
		//return sku_[0] == 0 && name_ == nullptr && price_ == 0 && !taxed_ && quantity_ == 0 && qtyNeeded_ == 0;
	}

	double Product::cost() const
	{
		return price();
	}
	
	void Product::sku(const char* value)
	{
		if (value){
			strncpy(sku_, value, MAX_SKU_LEN);
			sku_[MAX_SKU_LEN] = 0;
		}
	}
	void Product::price(double value)
	{
		price(value);
		
	}
	void Product::name(const char* value)
	{
		if (value){
			int len = strlen(value) + 1;
			clear();
			name_ = new char[len];
			strcpy(name_, value);
		}

	}
	void Product::quantity(int value)
	{
		quantity_ = value;
	}
	void Product::taxed(bool value)
	{
		taxed_ = value;

	}
	void Product::qtyNeeded(int value)
	{
		qtyNeeded_ = value;
	}

	const char* Product::sku() const
	{
		return sku_;
	}
	double Product::price() const
	{
		return price_;
	}
	const char* Product::name() const
	{
		return name_;
	}
	int	Product::quantity() const
	{
		return quantity_;
	}
	bool Product::taxed() const
	{
		return taxed_;
	}
	int Product::qtyNeeded() const
	{
		return qtyNeeded_;
	}

	bool Product::operator==(const char* ch)
	{
		return (strcmp(sku_, ch) == 0);
	}
	int Product::operator+=(int value)
	{
		return quantity_ += value;
	}
	int Product::operator-=(int value)
	{
		return quantity_ -= value;
	}

	std::istream& Product::read(std::istream& istr)
	{
		return istr;
	}
	std::ostream& Product::write(std::ostream& ostr)const
	{
		return ostr;
	}

	//Non-member IO operator overloads: 
	double operator+=(double& dvalue, const Product& P)
	{
		dvalue += P.price()*P.quantity();
		return dvalue;
	}


	std::ostream& operator<<(std::ostream& ostr, const Product& P)
	{		
		return P.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Product& P)
	{
		return P.read(istr);
	}

}
