// ***********************************************************************
/// Assignment       : < CST211 Exception.h >
/// Author           : < Nick Lavender >
/// Created          : < 04-03-2017 >
//
// Last Modified By : nickl
// Last Modified On : 09-20-2015
// ***********************************************************************
// <copyright file="Exception.h" company="Nick Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
/// < Exception Class for CST211 Assignments : Exception.cpp dependency >
// ***********************************************************************
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;
using std::left;



#define one_byte_leak char *byte_ = new char;

class Exception
{
public:
	Exception() : messa_g{ nullptr }
	{}

	~Exception() { Purge(); }
	void Purge()
	{
		delete[] messa_g;
		messa_g = nullptr;
	}

	Exception(char* ems_g) : messa_g{ ems_g }
	{
		messa_g = new char[strlen(ems_g) + 1];
		strcpy(messa_g, ems_g);
	}

	Exception(const Exception&rhs)
	{
		messa_g = new char[strlen(rhs.messa_g) + 1];
		*this = rhs;
	}

	Exception& operator =(const Exception&rhs);



	const char* getMessage();

	void setMessage(const char* ems_g)
	{
		if (messa_g != nullptr)
		{
			delete[] messa_g;
			strcpy(messa_g, ems_g);
		}
	}

private:
	char* messa_g;
};

