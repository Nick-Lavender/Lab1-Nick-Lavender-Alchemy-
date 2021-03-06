// ***********************************************************************
// Assembly         : Console Application Layer
// Author           : nickl
// Created          : 02-02-2017
//
// Last Modified By : nickl
// Last Modified On : 02-04-2017
// ***********************************************************************
// <copyright file="Cell.h" company="Nicholas Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#include "CellColor.h"
#include <Windows.h>




namespace ConsoleApplicationLayer
{

	enum CELL_OPERATIONS
	{
		DISPLAY,
		GOLD,
		RED,
		GREEN,
		BLUE,
		PURPLE,
		CAULDREN,
		SIDES,
	}CELL_OPs;

	class Cell : Icell
	{
	public:
		Cell();
		explicit Cell(SMALL_RECT dimensions_);
		Cell(const Cell &obj);
		virtual ~Cell();
		BOOL cellupdate() override;
		Cell& operator=(const Cell &rhs);
		void operator[](CELL_OPERATIONS);

		bool TileColor(CELL_OPERATIONS);
		void Set_Cell_colors(SHORT FG, SHORT BG, SHORT INTST);
		bool Covered();
		bool Action();
		bool Flag();
		bool Hot();

		void set_Hot(bool);
		void set_Flag(bool);
		void set_Action(bool);
		void set_Covered(bool);

	private:
		bool hot = false;
		bool flag = false;
		bool action = false;
		bool covered = true;

		CELL_COLOR cellcolor = CELL_COLOR(1, 2, 0);
	};///----------------------------------------------------------------------------------------------------------------------------------------< DEFINITIONS >

	inline Cell::Cell() : Icell{ SMALL_RECT{} }, hot{ false }, flag{ false }, action{ false }, covered{ false }///----------------------------< No Arg CTOR >
	{
	Set_Cell_colors(1, 2, 1);
	}
	inline Cell::Cell(SMALL_RECT dimensions) : hot{ false }, flag{ false }, action{ false }, covered{ false }///--------< One Arg CTOR > 
	{
		Set_Cell_colors(1, 2, 1);
	}
	inline Cell::Cell(const Cell &obj) : hot{ false }, flag{ false }, action{ false }, covered{ false }///---< Copy CTOR >
	{
		Set_Cell_colors(1, 2, 1);
		*this = obj;
	}
	inline Cell& Cell::operator=(const Cell& rhs)///<summary>--------------------------------------------------------------------->///< Op Equals / Assignment Operator ></summary>
	{
		if (this != &rhs)
		{
			flag = rhs.flag;								///--------------------------< Zeor Allocations >
			action = rhs.action;							///
			covered = rhs.covered;							///
			cellcolor = rhs.cellcolor;   					///---------< Must Initialize fg, bg, intensity >
			cellcolor.intensity = rhs.cellcolor.intensity;
		}
		return *this;
	}
	///<summary>< Cell States and ops ></summary>
	inline void Cell::operator[](CELL_OPERATIONS operator_)
	{
		switch (operator_)
		{
		case DISPLAY:
			break;
		case GOLD:
			TileColor(GOLD);
			break;
		case RED:
			break;
		case GREEN:
			break;
		case BLUE:
			break;
		case PURPLE:
			break;
		case CAULDREN:
			break;
		default:
			break;
		}
	}
	//
	inline bool Cell::TileColor(CELL_OPERATIONS operator_)
	{
		return true;
	}
	//
	inline Cell::~Cell() { }

	inline BOOL Cell::cellupdate()
	{
		
		return false;
	}
	//
	inline void Cell::Set_Cell_colors(SHORT FG = 1, SHORT BG = 2, SHORT INTST = 1)
	{
		cellcolor.fg = FG;
		cellcolor.bg = BG;
		cellcolor.intensity = INTST;
	}
	//
	inline bool Cell::Covered()///--------------------< QUERY : CELL STATE >
	{
		return covered;
	}
	//
	inline bool Cell::Action()///-----------------< QUERY : PERFORM ACTION >
	{
		return action;
	}
	//
	inline bool Cell::Flag()///----------------< QUERY : SPECIAL CONDITION >
	{
		return flag;
	}
	//
	inline bool Cell::Hot()///---------------< QUERY : CURSOR IS OVER CELL >
	{
		return hot;
	}
	//
	inline void Cell::set_Hot(bool hot_)///----< SET : CURSOR IS OVER CELL >
	{
		hot = hot_;
	}
	//
	inline void Cell::set_Flag(bool flag_)///---< SET : SPCECIAL CONDITION >
	{
		flag = flag_;
	}
	//
	inline void Cell::set_Action(bool action_)///---< SET : PERFORM ACTION >
	{
		action = action_;
	}
	//
	inline void Cell::set_Covered(bool covered_)///-----< SET : CELL STATE >
	{
		covered = covered_;
	}
}


