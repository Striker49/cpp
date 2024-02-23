#pragma once
#include "AAnimal.hpp"

class Cat : virtual public AAnimal
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
