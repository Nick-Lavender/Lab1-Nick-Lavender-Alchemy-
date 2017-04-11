// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-08-2017
//
// Last Modified By : nickl
// Last Modified On : 02-08-2017
// ***********************************************************************
// <copyright file="CoordinateDecorator.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include	"Decorator.h"

namespace ConsoleApplicationLayer
{
	class CoordinateDecorator : public Decorator
	{
	public:
		CoordinateDecorator(IConsoleContext* inner);		
		BOOL Draw() override;		

	private:
		ConInfoStruct *common_struct;
		IConsoleContext *inner_this;
	};

	inline CoordinateDecorator::CoordinateDecorator(IConsoleContext* inner) : Decorator(inner)
	{
		inner_this = inner;
		common_struct = &inner_this->GetInfoStruct();
	}

	inline BOOL CoordinateDecorator::Draw()
	{
		COORD temp = { 10, 4 };
		BOOL draw_succeed = inner_this->Draw();
		SetConsoleCursorPosition(common_struct->Hout, temp);
		Sleep(40);
		if (inner_this->FLAGS & DISPLAY_COORD)
		{
			cout << "X:" << setw(3) << common_struct->ConCursor.X
				<< "  Y:" << setw(3) << common_struct->ConCursor.Y;
			draw_succeed = true;
		}
		else
		{
			cout << "            ";
		}

		return draw_succeed;
	}
}

