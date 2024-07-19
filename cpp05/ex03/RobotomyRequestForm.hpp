#pragma once
#include "Form.hpp"

class RobotomyRequestForm : public Form
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
