#pragma once
#include "Animal.hpp"

class Cat : virtual public Animal
{
	private:
		std::string _type;
		Brain* 		_brain;
	public:
		Cat( void );
		~Cat( void );
		Cat( Cat const& src );

		Cat& operator=( Cat const& rhs);

		void makeSound() const;
		std::string getType() const;

};
