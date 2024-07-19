#include "Bureaucrat.hpp"

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

	try {
		std::cout << "Increasing grade of " << employee;
		employee.increaseGrade();
	}
		catch (Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "grade after increase: " << employee.getGrade() << std::endl << std::endl;
	try {
		std::cout << "Decreasing grade of " << employee2;
		employee2.decreaseGrade();
	}
		catch (Bureaucrat::GradeTooLowException& e){
			std::cout << e.what() << std::endl;
	}
	std::cout << "grade after decrease: " << employee2.getGrade() << std::endl << std::endl;

	try {
		std::cout << "Increasing grade of " << employee2;
		employee2.increaseGrade();
	}
		catch (Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "grade after increase: " << employee2.getGrade() << std::endl << std::endl;
	try {
		std::cout << "Decreasing grade of " << employee2;
		employee2.decreaseGrade();
	}
		catch (Bureaucrat::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "grade after decrease: " << employee2.getGrade() << std::endl << std::endl;

	return (0);
}