#include "easyfind.hpp"


int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	easyfind(vec, 1);

	// std::list<int> mylist;
	// vec.push_back(1);
	// vec.push_back(2);
	// vec.push_back(3);
	// vec.push_back(4);
	// easyfind(mylist, 4);

	std::deque<int> mydeque;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	easyfind(mydeque, 2);

	// char array[4] = {1, 2, 3, 4};
	// easyfind(array, 2);


}
