#pragma once
namespace ConsoleApplicationLayer
{
	struct Icell
	{
		explicit Icell(SMALL_RECT &DIMENTIONS_) : cell_area{DIMENTIONS_} { }
		virtual BOOL cellupdate();
		virtual ~Icell() = default;
	protected:
		SMALL_RECT &cell_area;
	};
}