#include "Span.hpp"

template <typename T>
void Span::addNumberImproved(T const begin, T const end)
{
	if ((end - begin + _vec.size()) <= _n && begin < end)
	{
		for (T it = begin; it != end; it++)
			addNumber(*it);
	}
	else
		throw(WrongRange());
}