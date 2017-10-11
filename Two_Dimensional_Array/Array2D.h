#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Array.h"
#include "Row.h"

template <typename T>
class Array2D
{
public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D & operator= (const Array2D & rhs);

	Row<T> operator[] (int index);
	Row<T> operator[] (int index) const;
	int getRow();
	void setRow(int rows);
	int getColumn();
	void setColumn(int columns);
	T & Select(int row, int column);

private:
	Array<T> m_array;
	int m_row;
	int m_col;
};

template <typename T>
Array2D<T>::Array2D()
	: m_array(0, 0), m_row(0), m_col(0)
{

}

template <typename T>
Array2D<T>::Array2D(int row, int col)
	: m_array(row * col, 0), m_row(row), m_col(col)
{

}

template <typename T>
Array2D<T>::Array2D(const Array2D<T> & copy)
	: m_array(copy.m_array), m_row(copy.m_row), m_col(copy.m_col)
{

}

template <typename T>
Array2D<T>::~Array2D()
{
	m_row = 0;
	m_col = 0;
}

template <typename T>
Array2D<T> & Array2D<T>::operator= (const Array2D<T> & rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_row = rhs.m_row;
		m_col = rhs.m_col;
	}

	return *this;
}

template <typename T>
Row<T> Array2D<T>::operator[] (int index)
{
	if (index < 0)
		throw Exception("Error: Index value cannot be negative");

	Row<T> row(*this, index);

	return row;
}

template <typename T>
Row<T> Array2D<T>::operator[] (int index) const
{
	if (index < 0)
		throw Exception("Error: Index value cannot be negative");

	const Row<T> row(const_cast<Array2D<T> &> (*this), index);

	return row;
}

template <typename T>
int Array2D<T>::getRow()
{
	return m_row;
}

template <typename T>
void Array2D<T>::setRow(int rows)
{
	if (rows < 0)
		throw Exception("Error: The number of rows cannot be negative");

	Array2D<T> new_array(rows, m_col);
	int rowsToCopy = (rows <= m_row ? rows : m_row);

	for (int row = 0; row < rowsToCopy; row++)
	{
		for (int col = 0; col < m_col; col++)
			new_array.Select(row, col) = this->Select(row, col);
	}

	this = new_array;
	m_row = rows;
}

template <typename T>
int Array2D<T>::getColumn()
{
	return m_col;
}

template <typename T>
void Array2D<T>::setColumn(int columns)
{
	if (columns < 0)
		throw Exception("Error: The number of columns cannot be negative");

	Array2D<T> new_array(m_row, columns);
	int columnsToCopy = (columns <= m_col ? columns : m_col);

	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < columnsToCopy; col++)
			new_array.Select(row, col) = this->Select(row, col);
	}

	this->m_array = new_array.m_array;
	m_col = columns;
}

template <typename T>
T & Array2D<T>::Select(int row, int column)
{
	return m_array[row * m_col + column];
}

#endif