#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

class Data
{
	private:
	public:
		std::string str;
		
		Data(void);
		Data(Data const& src);
		~Data(void);
		Data& operator=(Data const& rhs);
};
