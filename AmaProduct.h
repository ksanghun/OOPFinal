/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
/////////////////////////////////////////////

#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__

#include "Product.h"
#include "ErrorMessage.h"

namespace sict{
		
	class AmaProduct : public Product{
	private:
		char fileTag_;
		char unit_[11];
	protected:
		ErrorMessage err_;
	public:
		AmaProduct(char fileTag = 'N');
		const char* unit() const;
		void unit(const char* value);

	

		// Virtual method implementations //
		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);



		template<typename T>
		bool _input(std::istream& is, const char* lable, T b){
			std::cout << lable;
			is >> b;
			return ! is.fail();
		}	
	};
}
#endif


