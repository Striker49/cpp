#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const& src)
{
	*this = src;
}

Intern& Intern::operator=(Intern const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Intern::~Intern(void)
{
}

Form *Intern::makeForm(std::string const& formName, std::string const& target)
{
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *tmp = NULL;
	int	i;
	for (i = 0; i < 3; i++)
		if (forms[i] == formName)
			break;
	switch (i)
	{
		case 0:
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case 1:
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 2:
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(target));
		}
		default:
			std::cout << "The \"" << formName << "\" form doesn't exist. I might just be an Intern but I'm not stupid!" << std::endl;
	}
	return (tmp);
}