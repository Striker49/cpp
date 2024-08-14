#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>

enum
{
	STRING,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class Conversion
{
private:
	char _character;
	int _integer;
	double _double;
	float _float;
	int _type;
	std::string _pseudo;
public:
	Conversion(void);
	Conversion(Conversion const& src);
	~Conversion(void);
	Conversion& operator=(Conversion const& rhs);

	char getCharacter();
	int getInteger();
	double getDouble();
	float getFloat();
	int getType();
	std::string getPseudo();

	void setCharacter(std::string num);
	void setInteger(int num);
	void setDouble(double num);
	void setFloat(float num);
	void setType(int type);
	void setPseudo(std::string const type);

	void setNumber(std::string num, int type);
};
