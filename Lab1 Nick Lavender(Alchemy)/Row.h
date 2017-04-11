// ***********************************************************************
/// Assembly         : < CST211 A3 Array2D class ADT >
/// Author           : < Nick Lavender >
/// Created          : < 04-07-2017 >
//
// Last Modified By : nickl
// Last Modified On : 04-07-2017
// ***********************************************************************
// <copyright file="Row.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
/// <summary> Row.h helper class for Array2D class </summary>
// ***********************************************************************
#pragma once

template<class T>
class Array2D;


template<class T>
class Row
{
	friend class Array2D<T>;
public:
	T& operator[](int col_index);
private:
	Row(Array2D<T>& array_, int row_index);
	Array2D<T>& m_array;
	int m_row;
};

template<class T>
Row<T>::Row(Array2D<T> &array_, int row_index) : m_array{ array_ }, m_row{ row_index }
{ }

template<class T>
T& Row<T>::operator[](int col_index)
{
	return m_array.Select(m_row, col_index);
}
