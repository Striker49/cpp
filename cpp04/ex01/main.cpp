#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int size = 3;
	Animal* array[size];
	for (int i = 0; i <= size / 2; i++)
		array[i] = new Dog();
	for (int i = size / 2 + 1; i <= size; i++)
		array[i] = new Cat();

	std::cout << std::endl << std::endl;
	
	std::cout << array[0]->getType() << " ";
	array[0]->makeSound();
	std::cout << array[size]->getType() << " ";
	array[size]->makeSound();

	std::cout << std::endl << std::endl;
	
	for (int i = 0; i <= size; i++)
		delete array[i];
	
	return 0;
}