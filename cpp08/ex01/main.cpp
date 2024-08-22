#include "Span.hpp"

int main()
{
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

	Span rg = Span(100);
	rg.addRange(0, 50);
	// rg.displayVec();
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