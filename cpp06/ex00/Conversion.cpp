#include "Conversion.hpp"

Conversion::Conversion(void)
{
	_type = -1;
	_pseudo = "";
}

Conversion::Conversion(Conversion const& src)
{
	*this = src;
}

Conversion& Conversion::operator=(Conversion const& rhs)
{
	if (this != &rhs)
	{
		_character = rhs._character;
		_integer = rhs._integer;
		_double = rhs._double;
		_character = rhs._character;
		_type = rhs._type;
		_pseudo = rhs._pseudo;
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

bool Conversion::getOverflow()
{
	return (_overflow);
}

std::string Conversion::getPseudo()
{
	return (_pseudo);
}

void Conversion::setCharacter(char num)
{
	_character = static_cast<char>(num);
}

void Conversion::setInteger(int num)
{
	_integer = static_cast<int>(num);
}

void Conversion::setDouble(double num)
{
	_double = static_cast<double>(num);
}

void Conversion::setFloat(float num)
{
	_float = static_cast<float>(num);
}

void Conversion::setType(int type)
{
	_type = type;
}

void Conversion::setOverflow()
{
	_overflow = true;

}

void Conversion::setPseudo(std::string const pseudo)
{
	_pseudo = pseudo;
}

void Conversion::setNumber(std::string num, int type)
{
	setType(type);
	if (type == CHAR)
		setCharacter(num.c_str()[0]);
	if (type == INT)
		setInteger(static_cast<int>(strtod(num.c_str(), NULL)));
	if (type == DOUBLE)
		setDouble(static_cast<double>(strtod(num.c_str(), NULL)));
	if (type == FLOAT)
		setFloat(static_cast<float>(strtof(num.c_str(), NULL)));
}

	void Conversion::setCasts(char num)
	{
		_character = num;
		_integer = static_cast<int>(num);
		_float = static_cast<float>(num);
		_double = static_cast<double>(num);
	}

	void Conversion::setCasts(long int num)
	{
		_integer = num;
		_character = static_cast<char>(num);
		_float = static_cast<float>(num);
		_double = static_cast<double>(num);
	}

	void Conversion::setCasts(float num)
	{
		_float = num;
		_character = static_cast<char>(num);
		_integer = static_cast<int>(num);
		_double = static_cast<double>(num);
	}

	void Conversion::setCasts(double num)
	{
		_double = num;
		_character = static_cast<char>(num);
		_integer = static_cast<int>(num);
		_float = static_cast<float>(num);
	}

	void Conversion::setCasts(std::string const str)
	{
		_float = static_cast<float>(std::strtof(str.c_str(), NULL));
		_double = static_cast<double>(std::strtod(str.c_str(), NULL));
	}

