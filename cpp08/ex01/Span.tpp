#include "Span.hpp"

template <typename T>
void Span::addNumberImproved(T begin, T end)
{
	if ((end - begin + _vec.size()) <= _n)
	{
		for (T it = begin; it != end; it++)
			addNumber(*it);
	}
	else
		throw(WrongRange());
}