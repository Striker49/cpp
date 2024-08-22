#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class Span
{
private:
	size_t _n;
	std::vector<int> _vec;
public:
	Span(void);
	Span(int n);
	Span(Span const& src);
	~Span(void);
	Span& operator=(Span const& rhs);

	void addNumber(int number);
	void addRange(size_t begin, size_t end);
	int shortestSpan();
	int longestSpan();

	void displayVec();

};

class VecFull : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class NotEnoughElements : public std::exception
{
	public:
		virtual const char *what() const throw();
};

int generate();
