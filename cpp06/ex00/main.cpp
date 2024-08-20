#include "Conversion.hpp"

void printType(int type)
{
	std::cout << "Type: ";
	if (type == 1)
		std::cout << "CHAR" << std::endl;
	if (type == 2)
		std::cout << "INT" << std::endl;
	if (type == 3)
		std::cout << "FLOAT" << std::endl;
	if (type == 4)
		std::cout << "DOUBLE" << std::endl;
}

int forbiddenChar(char c)
{
	if ((c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122) && c != '.' && c != '-' && c != '+')
		return (1);
	return (0);
}


int checkIfPseudo(std::string const str)
{
	if (str.size() == 1)
		return (0);
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "nan" || str == "+inf" || str == "-inf")
		return (1);
	return (0);
}

int checkLimits(std::string const str)
{
	if (str.size() < 10)
		return (0);
	if (str.size() > 11 || checkIfPseudo(str))
		return (1);
	long int li = stoll(str, NULL);
	if (li < -2147483648 || li > 2147483647)
		return (1);
	return (0);
}

int stringParsing(std::string const str)
{
	int alpha = 0;
	int num = 0;
	int dot = 0;
	int f	= 0;
	int sign	= 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			num++;
		if (str[i] == '.')
			dot++;
		if (str[i] == 'f')
			f++;
		if (str[i] == '+' || str[i] == '-')
			sign++;
		if (isalpha(str[i]))
			alpha++;
		if (forbiddenChar(str[i]))
			return (1);
	}
	if (num == 0 || dot > 1 || f > 1 || sign > 1 || (sign == 1 && (str.front() != '-' && str.front() != '+')) || (alpha > 0 && str.size() > 1 && f == 0) || str.back() == '.' || str.front() == '.' || (isdigit(str[str.find('.')] - 1)))
		return (1);
	return (0);
}

void print_result(std::string const str, Conversion *a, int type)
{
	if (type == CHAR)
		a->setCasts(str[0]);
	else if (type == INT && !checkIfPseudo(str)&& !a->getOverflow())
		a->setCasts(strtol(str.c_str(), NULL, 10));
	else if (type == FLOAT)
		a->setCasts(strtof(str.c_str(), NULL));
	else if (type == DOUBLE)
		a->setCasts(strtod(str.c_str(), NULL));
	else
		a->setCasts(str);

	std::cout << "Input: " << str << std::endl;
	printType(type);
	std::cout << std::endl;
	if (a->getOverflow() || static_cast<unsigned char>(a->getCharacter()) > 255  || (str.size() != 1 && std::strtol(str.c_str(), NULL, 10) > 255) || (str.size() != 1 && std::strtol(str.c_str(), NULL, 10) < 0))
		std::cout << "char: " << "impossible" << std::endl;
	else if ((a->getCharacter() >= 0 && a->getCharacter() < 32) || static_cast<unsigned char>(a->getCharacter()) > 126)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << "\'" << a->getCharacter() << "\'" << std::endl;
	if (checkIfPseudo(str))
		std::cout << "int: " << "impossible" << std::endl;
	else if (a->getOverflow() == 1)
		std::cout << "int: " << "overflow" << std::endl;
	else
	{
		std::cout << "int: " << a->getInteger() << std::endl;
	}
	if (a->getFloat() < std::numeric_limits<float>::lowest() || a->getFloat() > std::numeric_limits<float>::max())
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << a->getFloat() << "f" << std::endl;
	if (a->getDouble() < std::numeric_limits<double>::lowest() || a->getDouble() > std::numeric_limits<double>::max())
		std::cout << "double: overflow" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(2) << a->getDouble() << std::endl;
}

int pseudo(std::string const str, Conversion a)
{
	if (str == "+inff" | str == "-inff" |str == "nanf")
	{
		a.setPseudo(str);
		return (FLOAT);
	}
	if (str == "+inf" | str == "-inf" |str == "nan")
	{
		a.setPseudo(str);
		return (DOUBLE);
	}
	return (0);
}

int ischar(std::string const str)
{
	for ( size_t i = 0; i < str.size(); i++)
	{
		if (((str[i] > 31 && str[i] < 48) || (str[i] > 57 && str[i] < 127)))
			return (1);
	}
	return (0);
}

int	parsing(std::string const str, Conversion a)
{
	int type = -1;
	if (str == "")
		return (-1);
	if (ischar(str) && str.size() == 1)
		return (CHAR);
	if ((type = pseudo(str, a)))
		return (type);
	if (stringParsing(str))
		return (-1);
	if (str.back() == 'f')
		return (FLOAT);
	if (str.find('.') != std::string::npos)
		return (DOUBLE);
	if (str.find('.') == std::string::npos)
		return (INT);
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
	{
		std::cout << "Invalid input..!" << std::endl;
		return (1);
	}
	if (checkIfPseudo(str) || checkLimits(str))
		a.setOverflow();
	a.setNumber(str, type);
	print_result(str, &a, type);
	return (0);
}

// int main()
// {

// 	std::string const str("0");
// 	// std::string const str("42");
// 	// std::string const str("24.0f");
// 	// std::string const str("1345.0f");
// 	// std::string const str("nan");
// 	// std::string const str("-2147483650");
// 	// std::string const str("2147483648");
// 	// std::string const str("2147483648333333333333333333333");
// 	// std::string const str("random_string");

// 	Conversion a;
// 	int type = parsing(str, a);
// 	if (type == -1)
// 	{
// 		std::cout << "Wrong parameter format..!" << std::endl;
// 		return (1);
// 	}
// 	if (checkIfPseudo(str) || checkLimits(str))
// 		a.setOverflow();
// 	a.setNumber(str, type);
// 	print_result(str, &a, type);
// 	return (0);
// }
