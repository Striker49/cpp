#pragma once
#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const&src);
		Bureaucrat& operator=(Bureaucrat const& rhs);
		const std::string	getName() const;
		int	getGrade() const;
		void	increaseGrade();
		void	decreaseGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low");
				}
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const& rhs);
