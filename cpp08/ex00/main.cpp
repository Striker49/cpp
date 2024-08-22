#include "easyfind.hpp"


int main()
{

	std::cout << std::endl << "----Vector----" << std::endl << std::endl;

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	print(vec);
	easyfind(vec, 1);

	std::cout << std::endl << "----List----" << std::endl << std::endl;

	std::list<int> mylist;
	mylist.push_back(5);
	mylist.push_back(6);
	mylist.push_back(7);
	mylist.push_back(8);
	print(mylist);
	easyfind(mylist, 8);

	std::cout << std::endl << "----Deque----" << std::endl << std::endl;

	std::deque<int> mydeque;
	mydeque.push_back(9);
	mydeque.push_back(10);
	mydeque.push_back(11);
	mydeque.push_back(12);
	print(mydeque);
	easyfind(mydeque, 11);
	easyfind(mydeque, 5);
	easyfind(mydeque, 0);
	easyfind(mydeque, -1);
	std::cout << std::endl;
}
