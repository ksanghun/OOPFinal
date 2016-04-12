/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////

#ifndef SICT_AIDAPP_H__
#define SICT_AIDAPP_H__

#include "Product.h"
#include "ErrorMessage.h"


namespace sict{
	class AidApp{
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		std::fstream datafile_;
		int noOfProducts_;	

		void pause() const;
		int	 menu();
		void loadRecs();
		void saveRecs();
		void listProducts() const;
		int SearchProducts(const char* sku)const;
		void addQty(const char* sku);
		void addProduct(bool isPerishable);

	public:
		AidApp(const char* filename);
		virtual ~AidApp();
		int run();
	};

}

#endif