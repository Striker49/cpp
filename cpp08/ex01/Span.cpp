#include "Span.hpp"

Span::Span(void)
{
	_n = 10;
}

Span::Span(int n)
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
	}
	return *this;
}

Span::~Span(void)
{
}

void Span::addNumber(int number)
{
	if (_vec.size() < _n)
		_vec.push_back(number);
	else
		throw(VecFull());
	// std::cout << _vec.back() << std::endl;
}

void Span::addRange(size_t begin, size_t end)
{
	std::cout << "entered addRange()" << std::endl;

	if (end < _n && begin >= 0 && begin < end)
	{
		std::cout << "Will start generating numbers" << std::endl;
		for (size_t i = begin; i < end; i++)
		{
			_vec[i] = generate();
			std::cout << "generated: " << _vec[i] << std::endl;
		}
	}
	else
		throw(VecFull());
	// std::cout << _vec.back() << std::endl;
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

void Span::displayVec()
{
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
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

int generate()
{
	srand(time(0));
	return(rand() % 100);
}