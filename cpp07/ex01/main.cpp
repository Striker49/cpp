#include "iter.tpp"

int main()
{
	char array[5] = {'a', 'b', 'c', 'd', 'e'};
	int array2[5] = {1, 2, 3, 4, 5};
	float array3[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

	std::cout << std::endl;
	std::cout << "----Print()----" << std::endl << std::endl;

	iter(array, 5, &print);
	std::cout << std::endl;
	iter(array2, 5, &print);
	std::cout << std::endl;
	iter(array3, 5, &print);
	std::cout << std::endl << std::endl;
	
	std::cout << "----Print() after increase()----" << std::endl << std::endl;

	iter(array, 5, &increase);
	iter(array, 5, &print);
	std::cout << std::endl;
	iter(array2, 5, &increase);
	iter(array2, 5, &print);
	std::cout << std::endl;
	iter(array3, 5, &increase);
	iter(array3, 5, &print);


	return (0);
}
