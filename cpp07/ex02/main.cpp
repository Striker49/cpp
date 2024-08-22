#include "Array.hpp"

int main()
{
	std::cout << "----Default Constructor----" << std::endl << std::endl;

	Array<int> a;
	std::cout << "Array<int> a" << std::endl << std::endl;
	std::cout << "Empty array" << std::endl;
	std::cout << "array size: " << a.size() << std::endl;
	std::cout << std::endl;

	std::cout << "----Constructor with parameter int size----" << std::endl << std::endl;

	Array<int> b(2);
	b[0] = 1;
	b[1] = 2;
<<<<<<< HEAD
	std::cout << "b: " << &b << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
	std::cout << "b[1]: " << b[1] << std::endl;
	try{
		std::cout << "b[2]: " << b[-1] << std::endl;
	}
	catch(std::exception &e){std::cout << "Index out of bounds..!" << std::endl;}
=======
	std::cout << "Array<int> b(2)" << std::endl << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
	std::cout << "b[1]: " << b[1] << std::endl;
	try{
		std::cout << "<< Trying to access b[2] >>" << std::endl;
		std::cout << "b[2]: " << b[2] << std::endl;
	}
	catch(std::exception &e){std::cout << "Index out of bounds..!" << std::endl;}
	std::cout << std::endl;
>>>>>>> d9c8fc03318d4aeba935ea3c8483bdb88608322f

	std::cout << "----Copy Assignment Operator----" << std::endl << std::endl;

	Array<int> c = b;
	std::cout << "Array<int> c = b" << std::endl << std::endl;
	std::cout << "c[0]: " << c[0] << std::endl;
	std::cout << "c[1]: " << c[1] << std::endl;
	c[0] = 5;
	std::cout << "<< Modified c[0] value >>" << std::endl;
	std::cout << "c[0]: " << c[0] <<std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
	std::cout << "array size: " << c.size() << std::endl;
	std::cout << std::endl;

	std::cout << "----Try to set oob value----" << std::endl << std::endl;

	Array<int> d(4);
	std::cout << "Array<int> d(4)" << std::endl << std::endl;
	std::cout << "array size: " << d.size() << std::endl;

	d[0] = 1;
	d[1] = 2;
	d[2] = 1;
	d[3] = 2;
	std::cout << "<< Trying to set d[4] value >>" << std::endl;
	try{
		d[4] = 1;
	}
	catch(std::exception &e){std::cout << "d[4]: Index out of bounds..!" << std::endl;}
	std::cout << std::endl;

	std::cout << "----Copy Constructor----" << std::endl << std::endl;
	Array<int> e(b);
	e[0] = 1;
	e[1] = 2;
	std::cout << "Array<int> e(b)" << std::endl << std::endl;
	std::cout << "e[0]: " << e[0] << std::endl;
	std::cout << "e[1]: " << e[1] << std::endl;
	b[0] = 5;
	std::cout << "<< Modified b[0] value >>" << std::endl;
	std::cout << "e[0]: " << e[0] <<std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
	std::cout << "array size: " << e.size() << std::endl;
	std::cout << std::endl;

	std::cout << "----Create float array----" << std::endl << std::endl;

	Array<float> f(4);
	f[0] = 1.1f;
	f[1] = 2.2f;
	f[2] = 3.3f;
	f[3] = 4.4f;
	std::cout << "Array<float> f(4)" << std::endl << std::endl;
	std::cout << "f[0]: " << f[0] << std::endl;
	std::cout << "f[1]: " << f[1] << std::endl;
	std::cout << "f[2]: " << f[2] << std::endl;
	std::cout << "f[3]: " << f[3] << std::endl;
	std::cout << "array size: " << f.size() << std::endl;
	std::cout << std::endl;

	std::cout << "----Create string array----" << std::endl << std::endl;

	Array<std::string> g(3);
	g[0] = "Born";
	g[1] = "to";
	g[2] = "code";
	std::cout << "Array<std::string> g(3)" << std::endl << std::endl;
	std::cout << "g[0]: " << g[0] << std::endl;
	std::cout << "g[1]: " << g[1] << std::endl;
	std::cout << "g[2]: " << g[2] << std::endl;
	std::cout << "array size: " << g.size() << std::endl;
	std::cout << std::endl;

	std::cout << "----Create char array----" << std::endl << std::endl;

	Array<char> h(3);
	h[0] = 'a';
	h[1] = 'b';
	h[2] = 'c';
	std::cout << "Array<char> h(3)" << std::endl << std::endl;
	std::cout << "h[0]: " << h[0] << std::endl;
	std::cout << "h[1]: " << h[1] << std::endl;
	std::cout << "h[2]: " << h[2] << std::endl;
	std::cout << "array size: " << h.size() << std::endl;
	std::cout << std::endl;
}
