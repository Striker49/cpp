#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	_array = static_cast<int*>(0);       
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_size = n;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = 0;
}

template <typename T>
Array<T>::Array(Array<T> const& src)
{
	*this = src;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& rhs)
{
	if (this != &rhs)
	{
		delete [] _array;
		_size = rhs._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _array;
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw(std::exception());
	return(_array[index]);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw(std::exception());
	return(_array[index]);
}
