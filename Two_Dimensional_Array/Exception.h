#ifndef EXCEPTION_H
#define EXCEPTION_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::ostream;

class Exception
{
	public:
		Exception();
		Exception(char * msg);
		Exception(const Exception & copy);
		~Exception();

		Exception & operator= (const Exception & rhs);
		const char * getMessage();
		void setMessage(char * msg);
		friend ostream & operator<< (ostream & stream, const Exception & except);

	private:
		char * m_msg;
};

#endif