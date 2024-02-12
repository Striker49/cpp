#include "Harl.hpp"

Harl::Harl( void )
{
	
}

Harl::~Harl( void )
{
	
}

void    Harl::debug( void )
{
    std::cout << "\033[0;32m" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"  << "\033[0;37m" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "\033[0;36m" << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"  << "\033[0;37m" << std::endl;
}

void    Harl::warning( void)
{
	std::cout << "\033[0;34m" << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."  << "\033[0;37m" << std::endl;
} 

void    Harl::error( void )
{
	std::cout << "\033[0;35m" << "This is unacceptable! I want to speak to the manager now."  << "\033[0;37m" << std::endl;
}

void    Harl::def( void )
{
	std::cout << "\033[1;31m" << "[ Probably complaining about insignificant problems ]" << "\033[0;37m" << std::endl;
}

void    Harl::complain( std::string level)
{
	std::string Sarray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int 		id;
	for (int i = 0; i < 4; i++)
	{
		if (level == Sarray[i])
		{
			id = i;
			std::cout << "\033[1;31m" << "[ " << Sarray[id] << " ]" << "\033[0;37m" << std::endl;
			break;
		}
		else
			id = 4;
	}
	switch (id)
	{
		case 0:
			(Harl::debug(), Harl::info(), Harl::warning(), Harl::error());
			break;
		case 1:
			(Harl::info(), Harl::warning(), Harl::error());
			break;
		case 2:
			(Harl::warning(), Harl::error());
			break;
		case 3:
			(Harl::error());
			break;
		default:
			(Harl::def());
			break;
	}
}
