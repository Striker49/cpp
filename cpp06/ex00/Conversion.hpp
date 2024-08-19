#pragma once
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

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
	bool _overflow;
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
	bool getOverflow();
	std::string getPseudo();

	void setCharacter(char num);
	void setInteger(int num);
	void setDouble(double num);
	void setFloat(float num);
	void setType(int type);
	void setOverflow(void);
	void setPseudo(std::string const type);
	void setCasts(char num);
	void setCasts(long int num);
	void setCasts(float num);
	void setCasts(double num);
	void setCasts(std::string const str);


	void setNumber(std::string num, int type);
};
