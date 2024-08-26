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
	size_t _count;
	std::vector<int> _vec;
public:
	Span(void);
	Span(unsigned int n);
	Span(Span const& src);
	~Span(void);
	Span& operator=(Span const& rhs);

	void addNumber(unsigned int number);
	void addRange(size_t begin, size_t end);
	int shortestSpan();
	int longestSpan();
	int size();

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

class WrongRange : public std::exception
{
	public:
		virtual const char *what() const throw();
};

void generate(int &element);
