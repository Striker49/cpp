#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat employee("John", 1);
	Bureaucrat employee2("Bob", 150);

	std::cout << std::endl << "-Wrong grade in constructor-" << std::endl;
	try{
		std::cout << "employee grade 0" << std::endl;
		Bureaucrat employee3("Erik", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		std::cout << "employee grade 151" << std::endl;
		Bureaucrat employee2("Jack", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << employee << std::endl;
	std::cout << employee2 << std::endl;



	std::cout << std::endl;
	std::cout << "------FORM PART------" << std::endl;
	std::cout << std::endl;

	std::cout << "form" << std::endl;
	Form form;
	std::cout << form << std::endl;
	std::cout << std::endl;
	try {
		std::cout << "form1, sign grade 0" << std::endl;
		Form form1("too high form", 0, 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "form2, sign grade 151" << std::endl;
		Form form2("too low form", 151, 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "form3, exec grade 0" << std::endl;
		Form form3("exec too high form", 150, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "form4, exec grade 151" << std::endl;
		Form form4("exec too low form", 150, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	Form form5("test form", 75, 75);
	std::cout << form5 << std::endl;
	std::cout << std::endl;

	std::cout << "John tries to sign \"" << form5.getName() << "\"" << std::endl;
	employee.signForm(form5);
	std::cout << std::endl;
	std::cout << "Bob tries to sign \"" << form5.getName() << "\"" << std::endl;
	employee2.signForm(form5);
	std::cout << std::endl;

	Form form6("test form 2", 75, 75);
	std::cout << form5 << std::endl;
	std::cout << std::endl;

	std::cout << "Bob tries to sign \"" << form6.getName() << "\"" << std::endl;
	employee2.signForm(form6);
	std::cout << std::endl;

	return (0);
}
