#pragma once
#include <iostream>
#include <fstream>
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
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const& src);
		~Form(void);
		Form& operator=(Form const& rhs);

		std::string const getName() const;
		bool	getSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		void	beSigned(Bureaucrat const& bureaucrat);
		void	execute(Bureaucrat const& executor) const;
		virtual void executeForm() const;

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

	class FormNotSigned : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Cannot execute, form not signed");
		}
	};
};

std::ostream & operator<<(std::ostream & o, Form const& rhs);
