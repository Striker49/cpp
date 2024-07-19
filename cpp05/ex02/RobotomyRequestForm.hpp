#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
private:
	std::string const _target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	~RobotomyRequestForm(void);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

	virtual void executeForm() const;
	std::string const& getTarget() const;
};
