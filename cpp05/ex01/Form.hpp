#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int			const	_sign_grade;
		int			const	_exec_grade;
	public:
		Form(void);
		Form(Form const& src);
		~Form(void);
		Form & operator=(Form const& rhs);
		Form(std::string name, int sign_grade, int exec_grade);

		std::string const getName() const;
		bool	getSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		void	beSigned(Bureaucrat const& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
	};
};

std::ostream & operator<<(std::ostream & o, Form const& rhs);
