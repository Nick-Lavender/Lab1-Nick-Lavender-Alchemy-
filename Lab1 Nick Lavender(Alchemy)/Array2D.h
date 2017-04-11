// ***********************************************************************
/// Assembly         : < CST211 A3 Array2d.h >
/// Author           : < Nick Lavender >
/// Created          : < 04-07-2017 >
//
// Last Modified By : nickl
/// Last Modified On : < 04-08-2017 >
// ***********************************************************************
// <copyright file="Array2d.h" company="Nick Lavender">
//     Copyright (c) . All rights reserved.
// </copyright>
/// <summary> 2D Array Class ADT </summary>
// ***********************************************************************
#pragma once
#include<iostream>
using std::ostream;

#include "Array.h"
#include "Row.h"

template<class T>
class Array2D
{
public:
	Array2D();
	Array2D(int rows, int cols);
	Array2D(const Array2D<T>&obj);
	~Array2D(){}

	Array2D<T>& operator=(const Array2D<T>&rhs);
	Row<T> operator[](int row_index);

	int GetRows();
	void SetRows(int rows);

	int GetCols();
	void SetCols(int cols); 
	
	T& Select(int row, int col);

private:
	int m_rows;
	int m_cols;
	Array<T> m_array;
};

template<class T>
Array2D<T>::Array2D() : m_rows{ 0 }, m_cols{ 0 } 
{	
	m_array = Array<T>();	
}

template<class T>
Array2D<T>::Array2D(int rows, int cols) : m_rows{ rows }, m_cols{ cols }
{
	m_array = Array<T>(rows * cols);	
}

template<class T>
Array2D<T>::Array2D(const Array2D<T>& obj) : m_rows{ 0 }, m_cols{ 0 }
{
	m_rows = obj.m_rows;
	m_cols = obj.m_cols;
	m_array = obj.m_array;
}

template<class T>
Array2D<T>& Array2D<T>::operator=(const Array2D<T>& rhs)
{
	if (this != &rhs)
	{
		m_rows = rhs.m_rows;
		m_cols = rhs.m_cols;
		m_array = rhs.m_array;
	}
	return *this;
}

template<class T>
Row<T> Array2D<T>::operator[](int row_index)
{
	return Row<T>(*this, row_index);
}

template<class T>
int Array2D<T>::GetRows()
{
	return m_rows;
}

template<class T>
void Array2D<T>::SetRows(int rows)
{
	Array<T> temp = Array<T>(rows * m_cols);
	int inner_limit = (rows < m_rows) ? rows : m_rows;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < inner_limit; j++)
		{
			temp[i][j] = m_array[i][j];
		}
	}
	m_array = temp;
}

template<class T>
int Array2D<T>::GetCols()
{
	return m_cols;
}


template<class T>
void Array2D<T>::SetCols(int cols)
{
	
}

template<class T>
T & Array2D<T>::Select(int row, int col)
{
	return m_array[row * m_cols + col];
}
