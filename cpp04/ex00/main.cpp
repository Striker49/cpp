#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	//Cat* k = new Animal(); 	Doesn't work because Animal isn't a cat
	//Cat* l = new Dog();		Doesn't work because Dog isn't a cat
	// Dog* k = new Animal(); 	Doesn't work because Animal isn't a dog
	// Dog* l = new Cat();		Doesn't work because Cat isn't a dog

	std::cout << std::endl << std::endl;

	std::cout << "j type: " << j->getType() << " " << std::endl;
	std::cout << "i type: " << i->getType() << " " << std::endl;
	std::cout << "meta sound:	";
	meta->makeSound(); //will output the animal sound!
	std::cout << "j sound	:	";
	j->makeSound(); //will output the dog sound!
	std::cout << "i sound	:	"	;
	i->makeSound(); //will output the cat sound!

	std::cout << std::endl << std::endl;

	WrongAnimal* m = new WrongCat();
	// WrongCat* m = new WrongAnimal(); Doesn't work because WrongAnimal isn't a cat
	// WrongAnimal* n = new Cat(); Doesn't work because WrongCat isn't a cat
	std::cout << "m type: " <<  m->getType() << " " << std::endl;
	std::cout << "m sound ";
	m->makeSound();

	std::cout << std::endl << std::endl;

	delete meta;
	delete j;
	delete i;
	delete m;
	
	return 0;
}