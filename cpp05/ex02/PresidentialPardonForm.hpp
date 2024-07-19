#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm
{
private:
	std::string const _target;
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm(void);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

	virtual void executeForm() const;
	std::string const& getTarget() const;
};
