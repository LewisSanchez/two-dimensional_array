#ifndef ROW_H
#define ROW_H

#include "Array2D.h"

template <typename T>
class Array2D;

template <typename T>
class Row
{
public:
	Row(Array2D<T> & array2D, int row);
	T & operator[] (int column);
	const T & operator[] (int column) const;

private:
	Array2D<T> & m_array2D;
	int m_row;
};

template <typename T>
Row<T>::Row(Array2D<T> & array2D, int row)
	: m_array2D(array2D), m_row(row)
{

}

template <typename T>
T & Row<T>::operator[] (int column)
{
	return m_array2D.Select(m_row, column);
}

template <typename T>
const T & Row<T>::operator[] (int column) const
{
	return m_array2D.Select(m_row, column);
}

#endif