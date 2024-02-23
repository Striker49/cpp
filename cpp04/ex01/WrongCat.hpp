#pragma once
#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
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
