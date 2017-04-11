// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-08-2017
//
// Last Modified By : nickl
// Last Modified On : 02-08-2017
// ***********************************************************************
// <copyright file="ConInfoStruct.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include <Windows.h>
#include <stdio.h>
#include "ConClientExcept.h"
#include "Cell.h"


namespace ConsoleApplicationLayer
{


	struct ConInfoStruct
	{
		ConInfoStruct();
		~ConInfoStruct();

		ConInfoStruct(const ConInfoStruct &obj);
		ConInfoStruct& operator=(const ConInfoStruct &rhs);
		void Purge();
		int rows;
		int cols;
		Cell cell;
		HWND Hwnd;
		HANDLE Hin;
		HANDLE Hout;
		HWND Hwndnew;
		HANDLE HnewIn;
		HANDLE HnewOUT;
		COORD MaxScrnSz;
		COORD ConCursor;
		DWORD oldConsoleMode;
		SMALL_RECT boardDimsns;
		DWORD numberOfRecordsRead;
		wchar_t* uniChar = nullptr;
		ConClientExcept* excep_error;
		DWORD ContextMenuConsoleMode;
		DWORD ContextMenuConsoleModeOld;
		static const DWORD maxRecords = 10;
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		INPUT_RECORD inputRecords[maxRecords];
		DWORD newConsoleMode = ENABLE_WINDOW_INPUT |
			ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;

		ConInfoStruct& GetReference() { return *this; }
		const CONSOLE_CURSOR_INFO CursorInfo = { 1, FALSE };
	};

	inline ConInfoStruct::ConInfoStruct()
		: rows(0)
		, cols(0)
		, Hwnd(nullptr)
		, Hin(nullptr)
		, Hout(nullptr)
		, Hwndnew(nullptr)
		, HnewIn(nullptr)
		, HnewOUT(nullptr)
		, oldConsoleMode()
		, numberOfRecordsRead()
		, excep_error(nullptr)
		, ContextMenuConsoleMode()
		, ContextMenuConsoleModeOld() { }
	inline ConInfoStruct::ConInfoStruct(const ConInfoStruct &obj)
		: rows(obj.rows)
		, cols(obj.cols)
		, Hwnd(obj.Hwnd)
		, Hin(obj.Hin)
		, Hout(obj.Hout)
		, Hwndnew(obj.Hwndnew)
		, HnewIn(obj.HnewIn)
		, HnewOUT(obj.HnewOUT)
		, oldConsoleMode(obj.oldConsoleMode)
		, numberOfRecordsRead(obj.numberOfRecordsRead)
		, excep_error(obj.excep_error)
		, ContextMenuConsoleMode(obj.ContextMenuConsoleMode)
		, ContextMenuConsoleModeOld(obj.ContextMenuConsoleModeOld)	{ }

	inline ConInfoStruct& ConInfoStruct::operator=(const ConInfoStruct& rhs)
	{
		Hwnd = rhs.Hwnd;
		Hin = rhs.Hin;
		Hout = rhs.Hout;
		Hwndnew = rhs.Hwndnew;
		HnewIn = rhs.HnewIn;
		HnewOUT = rhs.HnewOUT;
		oldConsoleMode = rhs.oldConsoleMode;
		numberOfRecordsRead = rhs.numberOfRecordsRead;
		excep_error = rhs.excep_error;
		ContextMenuConsoleMode = rhs.ContextMenuConsoleMode;
		ContextMenuConsoleModeOld = rhs.ContextMenuConsoleModeOld;
		return *this;
	}
	inline ConInfoStruct::~ConInfoStruct() { Purge(); }

	inline void ConInfoStruct::Purge()
	{
		if (excep_error)
		{
			excep_error->Purge();
			delete excep_error;
			excep_error = nullptr;
		}
	}
}
