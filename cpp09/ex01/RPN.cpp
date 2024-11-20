#include "RPN.hpp"

int wrongInput(std::string str) {
	std::cout << str << std::endl;
	std::cout << "usage: ./RPN \"1234567890+-*/ 	\"" << std::endl;
	return (1);
}

int parseInput(std::string str) {
	if (str.find_first_not_of("1234567890+-*/ 	") != std::string::npos)
		return (std::cout << "Error" << std::endl, 1);
	int num = 0;
	int op = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			num++;
		else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			op++;
			if (num < 2 || num - op < 1)
				return (std::cout << "Error" << std::endl, 1);
		}
	}
	if (num - op > 1)
		return (std::cout <<"Error" << std::endl, 1);
	return (0);
}

int	calc(int a, char c, int b) {
	switch (c) {
		case '*':
			// std::cout << b << " * " << a;
			return( b * a);
		case '/':
			// std::cout << b << " / " << a;
			if (a == 0)
				throw (std::runtime_error("Division by zero"));
			return( b / a);
		case '+':
			// std::cout << b << " + " << a;
			return( b + a);
		case '-':
			// std::cout << b << " - " << a;
			return( b - a);
		default:
			return (-1);
	}
}

int operate(std::stack<int> *stack, char c) {
	if (stack->empty() || stack->size() < 2)
		return (std::cout << "Error" << std::endl, 1);
	int a;
	int b;
	int result;
	a = stack->top();
	stack->pop();
	b = stack->top();
	stack->pop();
	try {
		result = calc(a, c, b);
	}
	catch (std::exception &e) {
		std::cout << "Error: division by 0 is impossible" << std::endl;
		return (1);
	}
	// std::cout << " = " << result << std::endl;
	stack->push(result);
	return (0);
}

int rpn(std::string str) {
	std::stack<int> stack;
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] >= 48 && str[i] <= 57)
			stack.push(std::stoi(str.substr(i, 1)));
		else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
			if (operate(&stack, str[i]))
				return (1);
	}
	std::cout << stack.top() << std::endl;
	return (0);
}

int main(int argc, char **argv) {
	if (argc != 2)
		return (wrongInput("Error"));
	std::string input(argv[1]);

	if (parseInput(input))
		return (1);
	if (rpn(input))
		return (1);
	return (0);
}