#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Bob"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const&src)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (this != &rhs)
	{
		_grade = rhs.getGrade();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const& rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(Form & form)
{
	if (form.getSigned() == true)
	{
		std::cout << form.getName() << " has already been signed" << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
	if (form.getSigned() == true)
		std::cout << getName() << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(Form & form)
{
	if (form.getSigned() == false)
	{
		throw(Form::FormNotSigned());
		return;
	}
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't execute \"" << form.getName() << "\" because " << e.what() << std::endl;
		return;
	}
}