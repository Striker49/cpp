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

static Form* makeShrubberyCreationForm(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

static Form* makeRobotomyRequestForm(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

static Form* makePresidentialPardonForm(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string const& formName, std::string const& target)
{
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (*Farray[])(std::string const&) = {makeShrubberyCreationForm, makeRobotomyRequestForm, makePresidentialPardonForm};
	int	i;
	for (i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			return (Farray[i](target));
		}
	}
	throw (Intern::FormNotFoundException());
}