#define _CRT_SECURE_NO_WARNINGS

#include"Exception.h"


Exception& Exception::operator=(const Exception &rhs)
{
	if(this != &rhs)
	{ 
		delete[] messa_g;
		messa_g = new char[strlen(rhs.messa_g) + 1];
		strcpy(messa_g, rhs.messa_g);
	}
	return *this;
}

const char * Exception::getMessage()
{
	return messa_g;
}
