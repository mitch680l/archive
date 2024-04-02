#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

using namespace std;
#include <iostream>
template <typename T>
class MyVector
{
public:
	MyVector();
	~MyVector();

	void Pushback(T item) noexcept;
	T GetAt(size_t index) const;
	size_t GetSize() const;
	void Resize(size_t newSize) noexcept;

private:
	T* m_array;
	size_t m_arraySize;
	size_t m_itemCount;

	void AllocateMemory(size_t size);
	void DeallocateMemory() noexcept;
	bool IsFull() const noexcept;

};

template <typename T>
size_t MyVector<T>::GetSize() const {
	return m_itemCount;
}

template <typename T>
bool MyVector<T>::IsFull() const noexcept
{
	if (m_itemCount == m_arraySize) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
MyVector<T>::MyVector()
{
	m_arraySize = 0;
	m_itemCount = 0;
	m_array = nullptr;
}

template <typename T>
MyVector<T>::~MyVector()
{
	DeallocateMemory();
}

template <typename T>
void MyVector<T>::AllocateMemory(size_t size) 
{
	if (m_array != nullptr) {
		throw logic_error("Already allocated!");
	}
	else 
	{
		m_array = new T[size];
		m_arraySize = size;
		m_itemCount = 0;
	}
}

template <typename T>
void MyVector<T>::DeallocateMemory() noexcept 
{
if(m_array != nullptr)
{
	delete[] m_array;
	m_array = nullptr;
	m_arraySize = 0;
	m_itemCount = 0;
}
}

template <typename T>
T MyVector<T>::GetAt(size_t index) const
{
	if (index < 0 || index >= m_itemCount) {
		throw out_of_range("Bad index!");
	}

	return m_array[index];
}

template <typename T>
void MyVector<T>::Resize(size_t newSize) noexcept
{
	T* newArray = new T[newSize];
	for (size_t i = 0; i < m_arraySize; i++) 
	{
		newArray[i] = m_array[i];
	}
	delete[] m_array;

	m_array = newArray;
	m_arraySize = newSize;
}

template <typename T>
void MyVector<T>::Pushback(T item) noexcept
{
	if(m_array == nullptr) 
	{
		AllocateMemory(5);
	}
	else if (IsFull())
	{
		Resize(m_arraySize + 5);
	}
	m_array[m_itemCount] = item;
	m_itemCount++;
}

#endif // !_MY_VECTOR_H