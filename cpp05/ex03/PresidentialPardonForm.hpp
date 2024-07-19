#pragma once
#include "Form.hpp"

class PresidentialPardonForm : public Form
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
