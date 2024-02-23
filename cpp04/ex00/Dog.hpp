#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string _type;		
	public:
		Dog( void );
		~Dog( void );
		Dog( Dog const& src );

		Dog& operator=( Dog const& rhs);

		virtual void makeSound() const;
		virtual std::string getType() const;
};
