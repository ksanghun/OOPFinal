/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////


#ifndef SICT_PRIDUCT_H__
#define SICT_PRIDUCT_H__
#include <iostream>
#include "general.h"
#include "Streamable.h"
namespace sict{
	class Product : public Streamable{
		char	sku_[MAX_SKU_LEN + 1];
		char*	name_;
		double	price_;
		bool	taxed_;
		int		quantity_;
		int		qtyNeeded_;

	private:
		void clear();		
		
		
		void setEmpty();
		void setValue(const Product& P);
		

	public:
		Product();
		Product(const char* csku, const char* cname, double dprice = 0.0, int iqtyNeeded = 0, bool bisTaxed = true );
		Product(Product& P);

		virtual ~Product();

		const char* sku() const;
		double		price() const;
		const char*	name() const;
		int			quantity() const;
		bool		taxed( ) const;
		int			qtyNeeded() const;

		bool		isEmpty() const;
		double		cost() const;

		void sku(const char* value);
		void price(double value);
		void name(const char* value);
		void quantity(int value);
		void taxed(bool value);
		void qtyNeeded(int value);



		Product& operator=(const Product& P);

		bool operator==(const char* ch);
		int operator+=(int value);
		int operator-=(int value);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};

	//Non-member IO operator overloads: 
	double operator+=(double& dvalue, const Product& P);

	std::ostream& operator<<(std::ostream& ostr, const Product& P);
	std::istream& operator>>(std::istream& istr, Product& P);

}
#endif