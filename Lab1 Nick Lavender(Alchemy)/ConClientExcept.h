// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-08-2017
//
// Last Modified By : nickl
// Last Modified On : 02-08-2017
// ***********************************************************************
// <copyright file="ConClientExcept.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

namespace ConsoleApplicationLayer
{
	class ConClientExcept
	{
	public:		
		ConClientExcept();		
		explicit ConClientExcept(DWORD Error);		
		ConClientExcept(const ConClientExcept &obj);		
		ConClientExcept& operator=(const ConClientExcept &rhs);		
		friend ostream& operator<<(ostream &OS, const ConClientExcept &out);		
		~ConClientExcept();		
		char* GetLastErrorStr(DWORD error);		
		void PushErrorToLog(DWORD error);		
		void RetrieveSystem_errorLog();		
		void Purge();

	private:		
		LPCSTR msg = nullptr;		
		LPCSTR *error_log = nullptr;
		int error_count = 0;
	};
}
