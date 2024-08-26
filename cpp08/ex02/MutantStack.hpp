#pragma once
#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		MutantStack<T>(void);
		MutantStack<T>(MutantStack const& src);
		~MutantStack<T>(void);
		MutantStack<T> &operator=(MutantStack<T> const& rhs);
		T &operator++(int);
		T &operator++();
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		void displayStack();
};

#include "MutantStack.tpp"