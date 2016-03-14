/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
// Date : 3/11/2016
/////////////////////////////////////////////


#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>
namespace sict{

	class ErrorMessage{

		char * message_;

	public:
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();

		void clear();
		void message(const char* errorMessage);
		bool isClear()const;
		const char* message() const;

		// Member operator //
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);	
	};

	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& err);
}
#endif

