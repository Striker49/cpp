#pragma once
#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal( void );
		virtual ~Animal( void );
		Animal( Animal const& src );

		Animal& operator=(Animal const& rhs);

		virtual std::string getType() const;
		virtual void makeSound() const;
};
