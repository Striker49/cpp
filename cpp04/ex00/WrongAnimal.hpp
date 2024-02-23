#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal( void );
		virtual ~WrongAnimal( void );
		WrongAnimal( WrongAnimal const& src );

		WrongAnimal& operator=(WrongAnimal const& rhs);

		std::string getType() const;
		void makeSound() const;
};
