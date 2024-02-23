#pragma once
#include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:
		std::string _type;
		Brain* 		_brain;
	public:
		Dog( void );
		~Dog( void );
		Dog( Dog const& src );

		Dog& operator=( Dog const& rhs);

		virtual void makeSound() const;
		virtual std::string getType() const;
};
