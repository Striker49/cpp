#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	int size = 3;
// 	Animal* bob = new Cat;
// 	// Cat* bob2 = new Cat;
// 	// bob2 = Cat(bob);
// 	Animal* array[size];
// 	for (int i = 0; i <= size / 2; i++)
// 		array[i] = new Dog();
// 	for (int i = size / 2 + 1; i <= size; i++)
// 		array[i] = new Cat();

// 	std::cout << std::endl << std::endl;
	
// 	std::cout << array[0]->getType() << " ";
// 	array[0]->makeSound();
// 	std::cout << array[size]->getType() << " ";
// 	array[size]->makeSound();

// 	std::cout << std::endl << std::endl;
	
// 	for (int i = 0; i <= size; i++)
// 		delete array[i];

// 	delete bob;
// 	// delete bob2;
	
// 	return 0;
// }

int main()
{
    std::cout << "Creating animals." << std::endl;
    Animal  *animalArray[10];
    for(int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            animalArray[i] = new Cat();
        else
            animalArray[i] = new Dog();
    }
    std::cout << "Creating animals done." << std::endl;
    std::cout << std::endl;
    std::cout << "Making animals sound." << std::endl;
    for(int i = 0; i < 10; i++)
        animalArray[i]->makeSound();
    std::cout << "Making animals sound done." << std::endl;
    std::cout << std::endl;
    std::cout << "Getting ideas from animals." << std::endl;
    std::cout << std::endl;
    std::cout << "Deep copy dog test." << std::endl;
    Dog *dogTest = new Dog();
    Dog copyDog = (*(Dog *)dogTest);
    Dog assignOpeDog;
    assignOpeDog = *dogTest;
    std::cout << "dogTest address:" << " " << dogTest << std::endl;
    std::cout << "copyDog address:" << " " << &copyDog << std::endl;
    std::cout << "assignOpeDog address:" << " " << &assignOpeDog << std::endl;
    std::cout << "Deep copy dog test done." << std::endl;
    std::cout << std::endl;
    std::cout << "Deep copy cat test." << std::endl;
    Cat *catTest = new Cat();
    Cat copyCat = (*(Cat *)catTest);
    Cat assignOpeCat;
    assignOpeCat = *catTest;
    std::cout << "catTest address:" << " " << catTest << std::endl;
    std::cout << "copyCat address:" << " " << &copyCat << std::endl;
    std::cout << "assignOpeCat address:" << " " << &assignOpeCat << std::endl;
    std::cout << "Deep copy cat test done." << std::endl;
    std::cout << std::endl;
    std::cout << "Deleting animals." << std::endl;
    for(int i = 0; i < 10; i++)
        delete animalArray[i];
    delete dogTest;
    delete catTest;
    std::cout << "Deleting animals done." << std::endl;
    return 0;
}
