#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
private:
	std::string const _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

	virtual void executeForm() const;
	std::string const& getTarget() const;
};
