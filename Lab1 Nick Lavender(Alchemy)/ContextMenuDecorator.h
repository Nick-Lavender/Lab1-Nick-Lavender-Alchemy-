// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-08-2017
//
// Last Modified By : nickl
// Last Modified On : 02-09-2017
// ***********************************************************************
// <copyright file="ContextMenuDecorator.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once

#include	"Decorator.h"


namespace ConsoleApplicationLayer
{
	class ContextMenuDecorator : public Decorator
	{
	public:
		ContextMenuDecorator(IConsoleContext *inner);
		~ContextMenuDecorator();
		BOOL InitWindow();
		BOOL Draw()override;

	private:
		IConsoleContext *this_inner;
		ConInfoStruct *common_struct;
	};

	inline ContextMenuDecorator::ContextMenuDecorator(IConsoleContext *inner)
		: Decorator(inner)
		, this_inner(inner)
		, common_struct(nullptr)
	{
		common_struct = &inner->GetInfoStruct();
	}

	inline ContextMenuDecorator::~ContextMenuDecorator()
	{
	}
	inline BOOL ContextMenuDecorator::InitWindow()
	{
		return returnVal;
	}
	inline BOOL ContextMenuDecorator::Draw()
	{
		return returnVal;
	}
}