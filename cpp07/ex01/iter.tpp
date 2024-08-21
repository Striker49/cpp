#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
void iter(T *ptr, int len, void (*function)(T&))
{
	for (int i = 0; i < len; i++)
		function(ptr[i]);
}

template <typename T>
void print(T element)
{
	std::cout << element << std::endl;
}

template <typename T>
void increase(T &element)
{
	element++;
}