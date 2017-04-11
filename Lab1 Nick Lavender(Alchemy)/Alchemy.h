#pragma once
#include"Decorator.h"
#include"Cell.h"
#include"Array2D.h"

namespace ConsoleApplicationLayer
{

	struct Alchemy : Decorator
	{
		Alchemy(IConsoleContext &inner);


		~Alchemy() {}
		BOOL Draw()override;

	private:
		Array2D<Cell> cellarray = Array2D<Cell>(common_struct.rows, common_struct.cols);
		bool act = true;
	};

	inline Alchemy::Alchemy(IConsoleContext &inner) : Decorator{ inner }
	{
		common_struct.cell.Left = 0;
		common_struct.cell.Right = 6;
		common_struct.cell.Top = 0;
		common_struct.cell.Bottom = 3;
	}

	inline BOOL Alchemy::Draw()
	{
		if (act)
		{
			cout << common_struct.boardDimsns.Right << "  columns:  " << common_struct.boardDimsns.Top << " rows. " << endl;
			act = false;
			return returnVal;
		}
		return false;
	}
}
