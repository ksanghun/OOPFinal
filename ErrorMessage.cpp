/////////////////////////////////////////////
// Modified by...
// Name : Sanghun Kim
// ID   : 015072150
// email: ksanghun@myseneca.ca 
// Date : 3/11/2016
/////////////////////////////////////////////


#include "ErrorMessage.h"
#include <cstring>
namespace sict{

	ErrorMessage::ErrorMessage()
	{
		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage)
	{
		message_ = nullptr;
		message(errorMessage);
	}

	ErrorMessage::~ErrorMessage()
	{
		clear();
	}

	void ErrorMessage::message(const char* errorMessage)
	{
		int len = strlen(errorMessage) + 1;
		message_ = new char[len];
		strcpy(message_, errorMessage);
	}

	void ErrorMessage::clear()
	{
		delete[] message_;
		message_ = nullptr;
	}

	ErrorMessage& ErrorMessage::operator=(const char* errorMessage)
	{
		if (errorMessage){
			clear();
			message(errorMessage);			
		}
		return *this;
	}

	bool ErrorMessage::isClear()const
	{
		return (message_ == nullptr);
	}

	const char* ErrorMessage::message() const
	{
		return message_;
	}


	// Helper operator //
	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& err)
	{		
		if (!err.isClear()){
			ostr << err.message();
		}
		return ostr;
	}
}