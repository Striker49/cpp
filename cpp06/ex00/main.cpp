#include "Conversion.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

int pseudo(std::string const str)
{
	if (str == "+inff" | str == "-inff" |str == "nanf")
		return (FLOAT);
	if (str == "+inf" | str == "-inf" |str == "nan")
		return (DOUBLE);
	return (0);
}

int ischar(std::string const str)
{
	for ( size_t i = 0; i < str.size(); i++)
	{
		if (str[i] < 33 || str[i] > 126)
			return (0);
	}
	return (1);
}

int	parsing(std::string const str, Conversion a)
{
	int type = -1;
	if (str == "")
		return (-1);
	if ((type = pseudo(str)))
		return (a.setNumber(str, type), type);
	if (str.find('.') != std::string::npos && str.back() == 'f')
		return (a.setFloat(static_cast<float>(std::strtod(str.c_str(), NULL))), FLOAT);
	if (str.find('.') != std::string::npos)
		return (a.setDouble(static_cast<double>(std::strtod(str.c_str(), NULL))), DOUBLE);
	if (ischar(str))
		return (CHAR);
	return (type);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments..!" << std::endl;
		return (1);
	}
	std::string const str(argv[1]);
	Conversion a;
	int type = parsing(str, a);
	if (type == -1)
		return (1);
	double un = std::strtod(argv[1], NULL);
	std::cout << "char: " << un << std::endl;
	std::cout << "char: " << static_cast<char>(un) << std::endl;
	std::cout << "int: " << static_cast<int>(un) << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(un) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(un) << "f" << std::endl;
	// Conversion a(un);
	// // convert_to_char();
	// std::cout << "char: " << static_cast<char *>(a.getCharacter()) << std::endl;
	// // convert_to_int();
	// std::cout << "int: " << static_cast<int *>(a.getCharacter()) << std::endl;
	// // convert_to_float();
	// std::cout << "float: " << a.getCharacter() << std::endl;
	// // convert_to_double();
	// std::cout << "double: " << a.getCharacter() << std::endl;
	return (0);
}