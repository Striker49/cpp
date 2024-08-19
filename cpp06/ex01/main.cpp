#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}

int main()
{
	Data *a = new Data;
	Data *b;
	uintptr_t ptr;
	a->str = "string";

	//a
	std::cout << "a: " << a << std::endl;
	std::cout << "a->str: " << a->str << std::endl;
	std::cout << "&a: " << &a << std::endl << std::endl;
	//ptr
	ptr = serialize(a);
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "&ptr: " << &ptr << std::endl << std::endl;
	//b
	b = deserialize(ptr);
	std::cout << "b: " << b << std::endl;
	std::cout << "b->str: " << b->str << std::endl;
	std::cout << "&b: " << &b << std::endl << std::endl;

	delete a;

	return (0);
}
