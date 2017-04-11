// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-08-2017
//
// Last Modified By : nickl
// Last Modified On : 02-08-2017
// ***********************************************************************
// <copyright file="IConsoleContext.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include <Windows.h>
#include <iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::end;
#include <iomanip>
using std::left;
using std::right;
using std::setw;
using std::setprecision;
#include "Icell.h"
#include "ConInfoStruct.h"


namespace ConsoleApplicationLayer
{
	enum KeyCode
	{
		QUIT = 81,
		DRAW_COORD = 67
	}*PKEYCODE, KEYCODE;

	typedef enum Options {
		DISPLAY_COORD = 0x01,
		SHOW_CONTEXT_MENU = 0x02,
		COLOR_UNDER_CURSOR = 0x04,
		WHITE_SCREEN = 0x08,
		BLACK_SCREEN = 0x10,
		LOG_LOCAL_VAR = 0x20,
		LOG_STRUCT_VAR = 0x40,
		INFO_BANNER = 0x80
	}*PCONFLAGS, CONFLAGS;

	class IConsoleContext : Icell
	{
	public:
		IConsoleContext(ConInfoStruct &struct_) : Icell(), FLAGS(0), CommStruct(struct_) {}
		ConInfoStruct& GetInfoStruct()
		{
			return CommStruct;
		}
		virtual ~IConsoleContext() = default;
		virtual BOOL Draw() = 0;
		SHORT FLAGS;
	protected:
		ConInfoStruct &CommStruct;
		BOOL returnVal = true;
	};
}