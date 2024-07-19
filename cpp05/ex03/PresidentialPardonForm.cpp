#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardon", 25, 5), _target("Someone")
{
	std::cout << getName() << " form has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : Form("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << getName() << " form has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : _target(src._target)
{
	// _target = src.getTarget();
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void PresidentialPardonForm::executeForm() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string const& PresidentialPardonForm::getTarget() const
{
	return (_target);
}
