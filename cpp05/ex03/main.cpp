#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat employee("John", 1);
	Bureaucrat employee2("Bob", 137);

	std::cout << std::endl;
	std::cout << employee << std::endl;
	std::cout << employee2 << std::endl;



	std::cout << std::endl;
	std::cout << "------Specific Form PART------" << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm form("Home");
	std::cout << form << std::endl;
	std::cout << std::endl;

	RobotomyRequestForm form1("Donal Trump");
	std::cout << form1 << std::endl;
	std::cout << std::endl;

	PresidentialPardonForm form2("Justin Bieber");
	std::cout << form2 << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "------JOHN PART------" << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "John tries executing form" << std::endl;
		employee.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "John tries executing form after signing it" << std::endl;
		employee.signForm(form);
		employee.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "John tries executing form1 after signing it" << std::endl;
		employee.signForm(form1);
		employee.executeForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "John tries executing form2 after signing it" << std::endl;
		employee.signForm(form2);
		employee.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "------BOB PART------" << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "Bob tries executing form after John already signed it" << std::endl;
		employee2.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "Bob tries executing form1 after John already signed it" << std::endl;
		employee2.executeForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "Bob tries executing form2 after John already signed it" << std::endl;
		employee2.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "------INTERN PART------" << std::endl;
	std::cout << std::endl;
	Intern internA;
	Form *rrf;

	rrf = internA.makeForm("robotomy request", "Bender");

	std::cout << rrf->getName() << ", Form signed(1) or not(0): " << rrf->getSigned() << ", sign grade " << rrf->getSignGrade() << ", execution grade " << rrf->getExecGrade() << std::endl;

	try {
		std::cout << "John tries executing form" << std::endl;
		employee.executeForm(*rrf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "John tries executing form after signing it" << std::endl;
		employee.signForm(*rrf);
		employee.executeForm(*rrf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	Form *rrf2;
	rrf2 = internA.makeForm("random", "whatever");

	return (0);
}
