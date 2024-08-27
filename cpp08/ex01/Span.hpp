#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Span
{
private:
	size_t _n;
	std::vector<int> _vec;
public:
	Span(void);
	Span(unsigned int n);
	Span(Span const& src);
	~Span(void);
	Span& operator=(Span const& rhs);

	void addNumber(unsigned int number);
	int shortestSpan();
	int longestSpan();
	int size();
	void displayVec();

	template <typename T>
	void addNumberImproved(T begin, T end);

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

#include "Span.tpp"