// ***********************************************************************
/// Assembly         : < CST211 A3 Array2D ADT helper Array.h ADT >
/// Author           : < Nick Lavender >
/// Created          : < 04-07-2017 >
//
// Last Modified By : nickl
// Last Modified On : 04-07-2017
// ***********************************************************************
// <copyright file="Array.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using std::ostream;
using std::cout;
using std::endl;

#include"Exception.h"

template<class T>
class Array
{
public:
	Array() : m_array{ nullptr }, start_index{ 0 }, size{ 0 } {}
	Array(int size, int start_index = 0);
	~Array() { Purge(); }
	void Purge() { delete[]m_array; m_array = nullptr; }
	Array(const Array<T>&obj);
	Array<T>& operator=(const Array<T>&rhs);
	T& operator[](int index);

	int GetStartIndex()const { return start_index; }
	void SetStartIndex(int new_idx) { start_index = new_idx; }

	int GetLength()const { return size; }
	void SetLength(int new_lngth);

private:
	T* m_array;
	int start_index;
	int size;
};

template<class T>
Array<T>::Array(int size_, int start_index_) : m_array{ nullptr }, size{ size_ }, start_index{ start_index_ }
{
	m_array = new T[size];
}

template<class T>
Array<T>::Array(const Array<T>& obj) : m_array{nullptr}, size{0}, start_index{0}
{
	*this = obj;
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	
	if (this != &rhs)
	{
		delete[]m_array;
		m_array = new T[rhs.size];
		for (int i = 0; i < rhs.size; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
	}
	size = rhs.size;
	start_index = rhs.start_index;
	return *this;
}

template<class T>
T & Array<T>::operator[](int index)
{
	int true_idx = index - start_index;
	if (true_idx < 0 || true_idx > size)
		throw Exception("index out of bounds.");
	return m_array[true_idx];
}

template<class T>
void Array<T>::SetLength(int new_lngth)
{
	if (new_lngth < 0) throw Exception("index out of bounds.");
	T* temp = new T[new_lngth];
	if (new_lngth < size)
	{
		for (int i = 0; i < new_lngth; i++)
		{
			temp[i] = m_array[i];
		}
		delete[]m_array;		
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			temp[i] = m_array[i];
		}
		delete[]m_array;		
	}
	m_array = temp;
	size = new_lngth;
}
