#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "iostream"
#include <cstdlib>
#include <time.h>

class D : public Base {};

Base *generate()
{
	int random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "* is from A Class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "* is from B Class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "* is from C Class" << std::endl;
	else
		std::cout << " is unidentifiable..!" << std::endl;

}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "& is from A Class" << std::endl;
		(void)a;
	}
	catch(const std::bad_cast&){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "& is from B Class" << std::endl;
		(void)b;
	}
	catch(const std::bad_cast&){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "& is from C Class" << std::endl;
		(void)c;
	}
	catch(const std::bad_cast&){
		std::cout << " is unidentifiable..!" << std::endl;
	}
}

int main()
{
	srand (time(NULL));

	Base *fst = generate();
	std::cout << "fst";
	identify(fst);
	std::cout << "fst reference";
	identify(*fst);
	std::cout << std::endl;


	Base *scd = generate();
	std::cout << "scd";
	identify(scd);
	std::cout << "scd reference";
	identify(*scd);
	std::cout << std::endl;

	Base *trd = new D;
	std::cout << "trd";
	identify(trd);
	std::cout << "trd reference";
	identify(*trd);
	std::cout << std::endl;

	delete fst;
	delete scd;
	delete trd;
}