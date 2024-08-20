#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const& src);
		~Array<T>(void);
		Array<T> &operator=(Array<T> const& rhs);
		T const&operator[](unsigned int index) const;
		T &operator[](unsigned int index);
};
