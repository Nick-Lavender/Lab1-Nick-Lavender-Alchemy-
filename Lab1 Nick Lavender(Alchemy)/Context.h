// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-08-2017
//
// Last Modified By : nickl
// Last Modified On : 02-08-2017
// ***********************************************************************
// <copyright file="Context.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include "IConsoleContext.h"
namespace ConsoleApplicationLayer
{

class ConsoleContext : public IConsoleContext
	{
	public:
		ConsoleContext() = delete;
		ConsoleContext(Icell celltype_);
		BOOL InitWindow();
		BOOL ReadInput();
		BOOL ProcessMouseInput();
		BOOL ProcessKeyInput();
		BOOL Update();
		ConInfoStruct& GetCommonStruct();
		ConsoleContext& operator=(const ConsoleContext& rhs) = delete;
		BOOL Draw() override;
		void Purge();
	private:
		Icell cell_;
	};

 ConsoleContext<Icell>::ConsoleContext(Icell celltype_) : IConsoleContext{ ConInfoStruct(); }
	{		
		InitWindow();
	}
	 BOOL ConsoleContext::InitWindow()
	{
		CommStruct.Hin = GetStdHandle(STD_INPUT_HANDLE);
		CommStruct.Hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleDisplayMode(CommStruct.Hout, CONSOLE_FULLSCREEN_MODE, nullptr);
		SetCursorPos(0, 0);

		GetConsoleScreenBufferInfo(CommStruct.Hout, &CommStruct.bufferInfo);
		SetConsoleScreenBufferSize(CommStruct.Hout, CommStruct.bufferInfo.dwMaximumWindowSize);
		SetConsoleCursorInfo(CommStruct.Hout, &CommStruct.CursorInfo);
		GetConsoleMode(CommStruct.Hin, &CommStruct.oldConsoleMode);

		return returnVal;
	}
	 BOOL ConsoleContext::ProcessMouseInput()
	{
		CommStruct.ConCursor = CommStruct.
			inputRecords[CommStruct.numberOfRecordsRead]
			.Event.MouseEvent.dwMousePosition;
		// TODO: Finish ProcessMouseInput().

		return returnVal;
	}

	 BOOL ConsoleContext::Update()
	{
		return returnVal;
	}

	 ConInfoStruct& ConsoleContext::GetCommonStruct()
	{
		return CommStruct;
	}

 BOOL ConsoleContext::ReadInput()
	{
		SetConsoleMode(CommStruct.Hin, CommStruct.newConsoleMode);
		ReadConsoleInput(CommStruct.Hin
			, CommStruct.inputRecords
			, CommStruct.maxRecords
			, &CommStruct.numberOfRecordsRead);
		if (CommStruct.numberOfRecordsRead)
		{
			DWORD index = 0;
			while (CommStruct.numberOfRecordsRead--) // TODO: IMMEDIATE: Processing this in reverse is a bad idea!
			{
				switch (CommStruct.inputRecords[CommStruct.numberOfRecordsRead].EventType)
				{
				case MOUSE_EVENT:
					ProcessMouseInput();
					Update();
					break;

				case KEY_EVENT:
					ProcessKeyInput();
					Update();
					break;

				case WINDOW_BUFFER_SIZE_EVENT:
					Update();
					break;

				case MENU_EVENT:
					Update();
					break;

				default:
					Update();
					break;
				}
			}
		}
		FlushConsoleInputBuffer(CommStruct.Hin);
		return returnVal; // TODO: Finish ReadInput()
	}

	 BOOL ConsoleContext::ProcessKeyInput()
	{
		if (CommStruct.inputRecords[CommStruct.numberOfRecordsRead]
			.Event.KeyEvent.uChar.AsciiChar == QUIT)
		{
			returnVal = false;
			// TODO: Finish ProcessKeyInput().
		}
		else
		{
			if (!CommStruct.inputRecords[CommStruct.numberOfRecordsRead]
				.Event.KeyEvent.bKeyDown &&
				CommStruct.inputRecords[CommStruct.numberOfRecordsRead]
				.Event.KeyEvent.uChar.AsciiChar == DRAW_COORD)
			{
				FLAGS = (FLAGS ^ DISPLAY_COORD);
				returnVal = true;
			}
		}
		return returnVal;
	}

	 BOOL ConsoleContext::Draw()
	{		
		return returnVal;
	}

	 void ConsoleContext::Purge()	{	}
}
