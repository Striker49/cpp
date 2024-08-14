#include "Conversion.hpp"

Conversion::Conversion(void)
{
}

// Conversion::Conversion(int a)
// {
// 	_character = static_cast<void *>(a);
// }

Conversion::Conversion(Conversion const& src)
{
	*this = src;
}

Conversion& Conversion::operator=(Conversion const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Conversion::~Conversion(void)
{
}

char Conversion::getCharacter()
{
	return (_character);
}

int Conversion::getInteger()
{
	return (_integer);
}

double Conversion::getDouble()
{
	return (_double);
}

float Conversion::getFloat()
{
	return (_float);
}

int Conversion::getType()
{
	return (_type);
}

std::string Conversion::getPseudo()
{
	return (_pseudo);
}

void Conversion::setCharacter(std::string num)
{
	_character = num.c_str()[0];
	std::cout << "charsetto: " << _character << std::endl;
}

void Conversion::setInteger(int num)
{
	_character = static_cast<int>(num);
	std::cout << "intsetto: " << _character << std::endl;
}

void Conversion::setDouble(double num)
{
	_double = static_cast<double>(num);
	std::cout << "doublesetto: " << static_cast<double>(_double) << std::endl;
}

void Conversion::setFloat(float num)
{
	_float = static_cast<float>(num);
	std::cout << "floatsetto: " << static_cast<float>(_float) << std::endl;
}

void Conversion::setType(int type)
{
	_type = type;
}

void Conversion::setPseudo(std::string const pseudo)
{
	_pseudo = pseudo;
}

void Conversion::setNumber(std::string num, int type)
{
	setType(type);
	if (type == CHAR)
		setCharacter(num);
	if (type == INT)
		setInteger(static_cast<int>(std::stoi(num)));
	if (type == DOUBLE)
		setDouble(static_cast<double>(strtod(num.c_str(), NULL)));
	if (type == FLOAT)
		setFloat(static_cast<float>(strtof(num.c_str(), NULL)));
}
