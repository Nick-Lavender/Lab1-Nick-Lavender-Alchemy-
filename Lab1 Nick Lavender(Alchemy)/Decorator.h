// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-08-2017
//
// Last Modified By : nickl
// Last Modified On : 02-08-2017
// ***********************************************************************
// <copyright file="Decorator.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include	"IConsoleContext.h"

namespace ConsoleApplicationLayer
{
	class Decorator : public IConsoleContext
	{
	public:
		explicit Decorator(IConsoleContext &inner) : IConsoleContext(inner), console_context(inner) { }
		BOOL Draw() override
		{
			draw_op_success = console_context.Draw();
			return draw_op_success;
		}

	protected:
		IConsoleContext &console_context;
		ConInfoStruct &common_struct = GetInfoStruct();
	private:
		BOOL draw_op_success = true;
	};
}
