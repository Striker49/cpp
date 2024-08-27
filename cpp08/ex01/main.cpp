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
		std::cout << std::endl << "Span sp = Span(5)" << std::endl << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Vector size: " << sp.size() << std::endl;
		sp.displayVec();
		std::cout << "<<Trying to add '20' to the stack>>" << std::endl;
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
		std::cout << std::endl << "Span sp = Span(5)" << std::endl << std::endl;
		sp.addNumber(6);
		std::cout << "Vector size: " << sp.size() << std::endl;
		sp.displayVec();

		std::cout << "<<Trying to find shortest/longest span>>" << std::endl;
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

	std::cout << std::endl << "----Creating new vector----" << std::endl << std::endl;

	std::vector<int> newVec;
	newVec.resize(10);
	for_each(newVec.begin(), (newVec.end()), generate);
	std::cout << "Vector size: " << newVec.size() << std::endl;
	for (std::vector<int>::iterator it = newVec.begin(); it != newVec.end(); it++)
		std::cout << *it << std::endl;

	std::cout << std::endl << "----Improved addNumber----" << std::endl;

	try{

		Span rg = Span(10);
		std::cout << std::endl << "rg.addNumberImproved(newVec.begin(), newVec.end());" << std::endl << std::endl;
		rg.addNumberImproved(newVec.begin(), newVec.end());
		std::cout << "rg.addNumberImproved(10);" << std::endl << std::endl;
		std::cout << "Vector size: " << rg.size() << std::endl;
		rg.displayVec();
		std::cout << ">>shortestSpan: " << rg.shortestSpan() << std::endl;
		std::cout << ">>longestSpan: " << rg.longestSpan() << std::endl;
	}
	catch(const WrongRange &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const VecFull &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const NotEnoughElements &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "----Improved addNumber exceed----" << std::endl;

	try{
		Span rg = Span(10);
		std::cout << std::endl << "Span rg = Span(10)" << std::endl << std::endl;
		std::cout << "rg.addNumberImproved(newVec.begin(), newVec.begin() + 5)" << std::endl << std::endl;
		rg.addNumberImproved(newVec.begin(), newVec.begin() + 5);
		rg.displayVec();
		std::cout << "rg.addNumberImproved(newVec.begin() + 5, newVec.end())" << std::endl << std::endl;
		rg.addNumberImproved(newVec.begin(), newVec.begin() + 5);
		rg.displayVec();
		std::cout << "rg.addNumberImproved(newVec.begin(), newVec.begin() + 5)" << std::endl << std::endl;
		rg.addNumberImproved(newVec.begin(), newVec.begin() + 5);
		rg.displayVec();
		std::cout << "Vector size: " << rg.size() << std::endl;
		rg.displayVec();
		std::cout << std::endl;
		std::cout << ">>shortestSpan: " << rg.shortestSpan() << std::endl;
		std::cout << ">>longestSpan: " << rg.longestSpan() << std::endl;
	}
	catch(const WrongRange &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const VecFull &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const NotEnoughElements &e)
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