#pragma once
#include <iostream>
#include <string>

class WrongAAnimal
{
	protected:
		std::string _type;

	public:
				WrongAAnimal( void );
		virtual ~WrongAAnimal( void ) = 0;
		virtual std::string getType() const;
		virtual void makeSound() const;
};
