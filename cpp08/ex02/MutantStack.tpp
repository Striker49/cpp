#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& src)
{
	*this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
T &MutantStack<T>::operator++(int)
{
	typename std::stack<T>::iterator tmp = *this;
	++(*this);
	return (tmp);
}

template <typename T>
T &MutantStack<T>::operator++()
{
	std::stack<T>::iterator++;
	return (*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
void MutantStack<T>::displayStack()
{
	typename MutantStack<T>::iterator ite = end();
	for (typename MutantStack<T>::iterator it = begin(); it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;

}
