#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 137), _target("Someone")
{
	std::cout << getName() << " form has been created!" << std::endl;
	// std::ostream file("Someone_shrubbery", std::ios::trunc);
	// write ASCII tree function
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	(void)target;
	std::cout << getName() << " form has been created!" << std::endl;
	// std::ostream file(target + "_shrubbery", std::ios::trunc);
	// write ASCII tree function
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
{
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream file(getTarget() + "_shrubbery");
	file << "       _-_ \n    /~~   ~~\\ \n /~~         ~~ \n{               } \n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\" << std::endl;
	std::cout << "Creating Shrubbery Tree!" << std::endl;
}

std::string const& ShrubberyCreationForm::getTarget() const
{
	return (_target);
}
