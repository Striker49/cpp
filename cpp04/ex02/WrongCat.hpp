#pragma once
#include "WrongAAnimal.hpp"

class WrongCat : virtual public WrongAAnimal
{
	private:
		std::string _type;
	public:
		WrongCat( void );
		~WrongCat( void );
		WrongCat( WrongCat const& src );

		WrongCat& operator=( WrongCat const& rhs);

		void makeSound() const;
		std::string getType() const;

};
