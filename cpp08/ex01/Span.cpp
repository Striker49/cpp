#include "Span.hpp"

Span::Span(void)
{
	_n = 10;
}

Span::Span(unsigned int n)
{
	_n = n;
}

Span::Span(Span const& src)
{
	*this = src;
}

Span& Span::operator=(Span const& rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_vec.clear();
		_vec = rhs._vec;
	}
	return *this;
}

Span::~Span(void)
{
}

void Span::addNumber(unsigned int number)
{
	if (_vec.size() < _n)
		_vec.push_back(number);
	else
		throw(VecFull());
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw(NotEnoughElements());
	std::sort(_vec.begin(), _vec.end());
	int temp = abs(_vec[0] - _vec[1]);
	for (size_t i = 1; i < _vec.size() - 1; i++)
	{
		if (abs(_vec[i + 1] - _vec[i]) < temp)
			temp = abs(_vec[i + 1] - _vec[i]);
	}
	return (temp);
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw(NotEnoughElements());
	std::sort(_vec.begin(), _vec.end());
	return (_vec.back() - _vec.front());
}

int Span::size()
{
	return (_vec.size());
}

void Span::displayVec()
{
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}

const char *VecFull::what() const throw()
{
	return ("Span is already full..!");
}

const char *NotEnoughElements::what() const throw()
{
	return ("Not enough elements to calculate span..!");
}

const char *WrongRange::what() const throw()
{
	return ("There's not enough room to add that many in the span..!");
}

void generate(int &element)
{
	element = rand() % 1000;
}
