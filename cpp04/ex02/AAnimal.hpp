#pragma once
#include <iostream>
#include <string>
#include "Brain.hpp"

#define PINK	"\e[38;5;212m"
#define WHITE	"\e[0;37m"
#define	BLACK	"\e[0;30m"
#define	RED		"\e[0;31m"
#define	GREEN	"\e[0;32m"
#define	YELLOW	"\e[0;33m"
#define	BLUE	"\e[0;34m"
#define	PURPLE	"\e[0;35m"
#define	CYAN	"\e[0;36m"

class AAnimal
{
	protected:
		std::string _type;

	public:
		virtual ~AAnimal() = 0;
		virtual std::string getType() const = 0;
		virtual void makeSound() const = 0;
};
