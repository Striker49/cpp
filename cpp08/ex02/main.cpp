#include "MutantStack.hpp"

int main()
{
	std::cout << std::endl << "----MutantStack----" << std::endl << std::endl;
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(5);
	mstack.displayStack();
	std::cout << "Stack size: "<< mstack.size() << std::endl;
	std::cout << "Element on top: "<< mstack.top() << std::endl;

	std::cout << std::endl << "<<Adding an element>>" << std::endl;
	mstack.push(42);
	mstack.displayStack();
	std::cout << "Stack size: "<< mstack.size() << std::endl;
	std::cout << "Element on top: "<< mstack.top() << std::endl;

	std::cout << std::endl << "<<Popping an element>>" << std::endl;
	mstack.pop();
	mstack.displayStack();
	std::cout << "Stack size: "<< mstack.size() << std::endl;
	std::cout << "Element on top: "<< mstack.top() << std::endl;


	std::cout << std::endl << "----List----" << std::endl << std::endl;
	std::list<int> mlist;

	mlist.push_back(1);
	mlist.push_back(1);
	mlist.push_back(2);
	mlist.push_back(3);
	mlist.push_back(5);
	std::list<int>::iterator ite = mlist.end();
	for(std::list<int>::iterator it = mlist.begin();it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	std::cout << "Stack size: "<< mlist.size() << std::endl;
	std::cout << "Element on top (at the back): "<< mlist.back() << std::endl;
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }
