#include "IntegerArray.h"
#include <algorithm>
#include <exception>
#include "bad_length.h"
#include "bad_range.h"

using namespace std;

IntegerArray::IntegerArray(int length) : m_length{ length }
{
	if (length > 0)
		m_data = new int[length] {};
	else
		throw bad_length();
		
}

IntegerArray::~IntegerArray()
{
	delete[] m_data;
}

IntegerArray::IntegerArray(const IntegerArray& a)
{
	reallocate(a.getLength());
	std::copy_n(a.m_data, m_length, m_data);
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
	if (&a == this)
		return *this;
	reallocate(a.getLength());
	std::copy_n(a.m_data, m_length, m_data);
	return *this;
}

int& IntegerArray::operator[](int index)
{
	if (index >= 0 && index < m_length)		
		return m_data[index];
	else
		throw bad_range();
}
void IntegerArray::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

void IntegerArray::reallocate(int newLength)
{
	erase();
	if (newLength <= 0)
		return;
	m_data = new int[newLength];
	m_length = newLength;
}

void IntegerArray::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data{ new int[newLength] };
	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
		std::copy_n(m_data, elementsToCopy, data);
	}
	delete[] m_data;

	m_data = data;
	m_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)
{
	if (!(index >= 0 && index <= m_length))
		throw bad_range();
	int* data{ new int[m_length + 1] };
	std::copy_n(m_data, index, data);
	data[index] = value; 
	std::copy_n(m_data + index, m_length - index, data + index + 1);
	delete[] m_data;
	m_data = data;
	++m_length;
}
void IntegerArray::remove(int index)
{
	if (!(index >= 0 && index < m_length))
		throw bad_range();
	if (m_length == 1)
	{
		erase();
		return;
	}
	int* data{ new int[m_length - 1] };
	std::copy_n(m_data, index, data);
	std::copy_n(m_data + index + 1, m_length - index - 1, data + index);
	delete[] m_data;
	m_data = data;
	--m_length;
}

void IntegerArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}
int IntegerArray::getLength() const
{
	return m_length;
}