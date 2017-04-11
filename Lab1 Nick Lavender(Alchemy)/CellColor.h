// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-03-2017
//
// Last Modified By : nickl
// Last Modified On : 02-04-2017
// ***********************************************************************
// <copyright file="CellColor.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include <Windows.h>

namespace ConsoleApplicationLayer
{
	typedef struct cellColor
	{
		cellColor(SHORT fg_ = 1, SHORT bg_ = 2, SHORT intensity_ = 1)
			: fg{ fg_ }
			, bg{ bg_ }
			, intensity{ intensity_ }
		{}
		SHORT fg;
		SHORT bg;
		SHORT intensity;
	} *PCELL_COLOR, CELL_COLOR;
}
