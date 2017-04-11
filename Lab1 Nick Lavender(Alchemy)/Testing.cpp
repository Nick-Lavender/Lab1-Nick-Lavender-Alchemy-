// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-05-2017
//
// Last Modified By : nickl
// Last Modified On : 02-06-2017
// ***********************************************************************
// <copyright file="Testing.cpp" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::endl;

#include <Windows.h>
#include <crtdbg.h> 

#include "Icell.h"

#include	"Context.h"
#include	"Alchemy.h"

using namespace ConsoleApplicationLayer;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ConsoleContext console = ConsoleContext(Cell({ 0, 0, 6, 3 }));

	Alchemy alchemy = Alchemy(console);

	while (alchemy.Draw() && console.ReadInput());


	return 0;
}


