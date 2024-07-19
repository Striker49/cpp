#include "Bureaucrat.hpp"

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
