#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define PINK	"\e[38;5;212m"
#define WHITE	"\e[0;37m"
#define	BLACK	"\e[0;30m"
#define	RED		"\e[0;31m"
#define	GREEN	"\e[0;32m"
#define	YELLOW	"\e[0;33m"
#define	BLUE	"\e[0;34m"
#define	PURPLE	"\e[0;35m"
#define	CYAN	"\e[0;36m"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const& src);
		virtual ~AMateria(void);
		AMateria& operator=(AMateria const& rhs);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
