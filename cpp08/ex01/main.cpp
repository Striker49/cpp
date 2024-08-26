#include "Span.hpp"

int main()
{
	srand(time(0));

	std::cout << std::endl << "----Subject example----" << std::endl;
	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const VecFull &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const NotEnoughElements &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "----Too many addNumber----" << std::endl;
	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(20);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const VecFull &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const NotEnoughElements &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "----Only one element in vector----" << std::endl;
	try{
		Span sp = Span(5);
		sp.addNumber(6);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const VecFull &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const NotEnoughElements &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "----Improved addNumber----" << std::endl;

	try{
		Span rg = Span(10);
		rg.addRange(0, 9);
		std::cout << "<<Generated Vector>>" << std::endl;
		std::cout << std::endl;
		rg.displayVec();
		std::cout << std::endl;
		std::cout << "Vector size: " << rg.size() << std::endl;
		std::cout << ">>shortestSpan: " << rg.shortestSpan() << std::endl;
		std::cout << ">>longestSpan: " << rg.longestSpan() << std::endl;
	}
	catch(const WrongRange &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }