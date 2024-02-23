#pragma once
#include "Animal.hpp"

class Cat : virtual public Animal
{
	private:
		std::string _type;
	public:
		Cat( void );
		~Cat( void );
		Cat( Cat const& src );

		Cat& operator=( Cat const& rhs);

		virtual void makeSound() const;
		virtual std::string getType() const;

};
