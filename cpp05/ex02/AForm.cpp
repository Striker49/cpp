#include "AForm.hpp"

AForm::AForm(void) : _name("some AForm"), _signed(false), _sign_grade(150), _exec_grade(150)
{
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (this->_sign_grade < 1)
		throw (AForm::GradeTooHighException());
	if (this->_sign_grade > 150)
		throw (AForm::GradeTooLowException());
	if (this->_exec_grade < 1)
		throw (AForm::GradeTooHighException());
	if (this->_exec_grade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const& src) : _name(src._name), _signed(false), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	*this = src;
}

AForm& AForm::operator=(AForm const& rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

AForm::~AForm(void)
{
}

std::string const AForm::getName() const
{
	return (_name);
}
bool	AForm::getSigned() const
{
	return (_signed);
}

int		AForm::getSignGrade() const
{
	return (_sign_grade);
}

int		AForm::getExecGrade() const
{
	return (_exec_grade);
}

void	AForm::beSigned(Bureaucrat const& bureaucrat)
{

	if (bureaucrat.getGrade() > getSignGrade())
		throw (AForm::GradeTooLowException());
	else
		this->_signed = true;
}

void	AForm::execute(Bureaucrat const& bureaucrat) const
{
	if (bureaucrat.getGrade() > getExecGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << bureaucrat.getName() << " executed " << getName() << std::endl;
		executeForm();
	}
}



std::ostream & operator<<(std::ostream & o, AForm const &rhs)
{
	o << rhs.getName() << ", AForm signed(1) or not(0): " << rhs.getSigned() << ", sign grade " << rhs.getSignGrade() << ", execution grade " << rhs.getExecGrade();
	return (o);
}

void AForm::executeForm() const
{
}