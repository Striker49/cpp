#include "Form.hpp"

Form::Form(void) : _name("some Form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (this->_sign_grade < 1)
		throw (Form::GradeTooHighException());
	if (this->_sign_grade > 150)
		throw (Form::GradeTooLowException());
	if (this->_exec_grade < 1)
		throw (Form::GradeTooHighException());
	if (this->_exec_grade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(Form const& src) : _name(src._name), _signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	*this = src;
}

Form& Form::operator=(Form const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Form::~Form(void)
{
}

std::string const Form::getName() const
{
	return (_name);
}
bool	Form::getSigned() const
{
	return (_signed);
}

int		Form::getSignGrade() const
{
	return (_sign_grade);
}

int		Form::getExecGrade() const
{
	return (_exec_grade);
}

void	Form::beSigned(Bureaucrat const& bureaucrat)
{

	if (bureaucrat.getGrade() > getSignGrade())
		throw (Form::GradeTooLowException());
	else
		this->_signed = true;
}

void	Form::execute(Bureaucrat const& bureaucrat) const
{
	if (bureaucrat.getGrade() > getExecGrade())
		throw (Form::GradeTooLowException());
	else
	{
		std::cout << bureaucrat.getName() << " executed " << getName() << std::endl;
		executeForm();
	}
}



std::ostream & operator<<(std::ostream & o, Form const &rhs)
{
	o << rhs.getName() << ", Form signed(1) or not(0): " << rhs.getSigned() << ", sign grade " << rhs.getSignGrade() << ", execution grade " << rhs.getExecGrade();
	return (o);
}

void Form::executeForm() const
{
}