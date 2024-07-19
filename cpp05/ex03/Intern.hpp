#pragma once
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	public:
		Intern(void);
		Intern(Intern const& src);
		~Intern(void);
		Intern& operator=(Intern const& rhs);

		Form *makeForm(std::string const& formName, std::string const& target);
};
