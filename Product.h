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
		Product(const char* csku, const char* cname,  double dprice = 0.0, int iqtyNeeded =0, bool bisTaxed = true);
		Product(Product& P);

		~Product();

		// Getter ================//
		const char* sku() const;
		double		price() const;
		const char*	name() const;
		int			quantity() const;
		bool		taxed( ) const;
		int			qtyNeeded() const;
		bool		isEmpty() const;
		// Setter =====================//
		void		sku(const char* csku);
		void		price(double value);
		void		name(const char* cname);
		void		quantity(int value);
		void		taxed(bool value);
		void		qtyNeeded(int value);
		//===============================//

		double		cost() const;


		Product& operator=(const Product& P);

		bool operator==(const char* ch);
		int operator+=(int value);
		int operator-=(int value);

	};

	//Non-member operator overloads: 
	double operator+=(double& dvalue, const Product& P);

	//Non-member IO operator overloads: 
	std::ostream& operator<<(std::ostream& ostr, const Product& P);
	std::istream& operator>>(std::istream& istr, Product& P);

}
#endif