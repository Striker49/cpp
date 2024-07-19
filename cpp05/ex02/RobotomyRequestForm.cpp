#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45), _target("Someone")
{
	std::cout << getName() << " form has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << getName() << " form has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
{
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

void	RobotomyRequestForm::executeForm() const
{
	std::cout << "Brrrrrrrrrr...Vrrrrrrrrrrr...Grrrrrrrrrrrrrrr..." << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << getTarget() << "'s robotomy has failed..!" << std::endl;
}

std::string const& RobotomyRequestForm::getTarget() const
{
	return (_target);
}