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
#include <string.h>


namespace sict{

	Product::Product()
	{
		setEmpty();
	}

	Product::Product(const char* csku, const char* cname,  double dprice, int iqtyNeeded, bool bisTaxed)
		:name_(nullptr), quantity_(0){

		sku(csku);
		name(cname);	
		price(dprice);
		qtyNeeded(iqtyNeeded);
		taxed(bisTaxed);
	}

	Product::Product(Product& P)
	{
		setValue(P);
	}


	Product::~Product()
	{
		clear();
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
		clear();
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
		return !(sku_[0] || name_ || price_ || taxed_ || quantity_ || quantity_ || qtyNeeded_);
	}

	double Product::cost() const
	{
		return ((taxed_) ? price_*(1.0+TAX) : price_);		
	}
	
	void Product::sku(const char* csku)
	{
		if (csku){
			strncpy(sku_, csku, MAX_SKU_LEN);
			sku_[MAX_SKU_LEN] = 0;
		}
	}
	void Product::price(double value)
	{
		price_ = value;
		
	}
	void Product::name(const char* cname)
	{
		if (cname){
			int len = strlen(cname) + 1;
			name_ = new char[len];
			strcpy(name_, cname);
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
		return !strcmp(sku_, ch);
	}
	int Product::operator+=(int value)
	{
		return quantity_ += value;
	}
	int Product::operator-=(int value)
	{
		return quantity_ -= value;
	}


	//Non-member operator overloads: 
	double operator+=(double& dvalue, const Product& P)
	{
		dvalue += P.cost()*P.quantity();
		return dvalue;
	}


	//Non-member IO operator overloads: 
	std::ostream& operator<<(std::ostream& ostr, const Product& P)
	{		
		return P.write(ostr, true);
	}
	std::istream& operator>>(std::istream& istr, Product& P)
	{
		return P.read(istr);
	}

}
