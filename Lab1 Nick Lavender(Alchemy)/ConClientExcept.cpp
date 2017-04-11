// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-02-2017
//
// Last Modified By : nickl
// Last Modified On : 02-05-2017
// ***********************************************************************
// <copyright file="ConClientExcept.cpp" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************

#include	"ConClientExcept.h"
using namespace ConsoleApplicationLayer;

namespace ConsoleApplicationLayer
{
	ConClientExcept::ConClientExcept() : msg(nullptr), error_log(nullptr), error_count(0)
	{
	}
	ConClientExcept::ConClientExcept(DWORD Error)
	{
		msg = GetLastErrorStr(Error);
		cout << msg << endl;
	}
	ConClientExcept::ConClientExcept(const ConClientExcept& obj)
	{
		if (obj.msg)
		{
			msg = new char[strlen(obj.msg) + 1];
			strcpy(const_cast<char*>(msg), obj.msg);

		}
	}
	ConClientExcept& ConClientExcept::operator=(const ConClientExcept & rhs)
	{
		if (this != &rhs)
		{
			msg = new char[strlen(rhs.msg) + 1];
			strcpy(const_cast<char*>(msg), rhs.msg);
		}
		return *this;
	}
	ConClientExcept::~ConClientExcept()
	{

	}
	char* ConClientExcept::GetLastErrorStr(DWORD error)
	{
		LPSTR messageBuffer = nullptr;

		auto errorMessageID = error;
		if (errorMessageID)
		{
			size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS,
				nullptr, errorMessageID,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				reinterpret_cast<LPSTR>(&messageBuffer), 0, nullptr);
		}
		return reinterpret_cast<char*>(messageBuffer);
	}
	void ConClientExcept::PushErrorToLog(DWORD error)
	{
		msg = static_cast<char*>(GetLastErrorStr(error));
		LPCSTR *temp = nullptr;
		temp = new LPCSTR[error_count + 1];
		for (int i = 0; i < error_count; i++)
		{
			temp[i] = new char[strlen(error_log[i]) + 1];
			strcpy(const_cast<char*>(temp[i]), error_log[i]);
		}
		for (int i = 0; i < error_count; i++)
		{
			delete[] error_log[i];
		}
		delete[] error_log;

		temp[error_count] = new char[strlen(msg) + 1];
		strcpy(const_cast<char*>(temp[error_count]), msg);
		error_log = temp;
		error_count++;
	}
	void ConClientExcept::RetrieveSystem_errorLog()
	{
		for (auto i = 0; i < error_count; i++)
		{
			cout << error_log[i] << endl;
		}
	}
	void ConClientExcept::Purge()
	{		
			for (int i = 0; i < error_count; i++)
			{
				delete[] error_log[i];
			}
			delete[] error_log;
			error_log = nullptr;		
	}
	ostream& operator<<(ostream &OS, const ConClientExcept &out)
	{
		OS << out.msg;
		return OS;
	}
}
