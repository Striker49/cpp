#include "Span.hpp"

Span::Span(void)
{
	_n = 10;
	_count = 0;
}

Span::Span(unsigned int n)
{
	_n = n;
	_count = 0;
	_vec.resize(n);
}

Span::Span(Span const& src)
{
	*this = src;
}

Span& Span::operator=(Span const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Span::~Span(void)
{
}

void Span::addNumber(unsigned int number)
{
	if (_count < _n)
	{
		_count++;
		_vec.push_back(number);
	}
	else
		throw(VecFull());
}

void Span::addRange(size_t begin, size_t end)
{
	if (end <= _n && begin < end)
	{
		std::for_each(_vec.begin() + begin, _vec.begin() + end, generate);
		_count = _n;
	}
	else
		throw(WrongRange());
}

int Span::shortestSpan()
{
	if (_count <= 1)
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
	if (_count <= 1)
		throw(NotEnoughElements());
	std::sort(_vec.begin(), _vec.end());
	return (_vec.back() - _vec.front());
}

int Span::size()
{
	return (_n);
}

void Span::displayVec()
{
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.begin() + _count; it++)
		std::cout << *it << std::endl;
}

const char *VecFull::what() const throw()
{
	return ("Vec already full..!");
}

const char *NotEnoughElements::what() const throw()
{
	return ("Not enough elements to calculate span..!");
}

const char *WrongRange::what() const throw()
{
	return ("Range doesn't fit in the span..!");
}

void generate(int &element)
{
	element = rand() % 1000;
}