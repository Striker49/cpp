#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name(""), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) : _name(name), _hp(hp), _ep(ep), _ad(ad)
{
	std::cout << "ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const& src) : _name(src._name), _hp(100), _ep(50), _ad(20)
{
	*this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return(*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " has been recycled" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << "\033[0;30mClapTrap " << this->_name << " is unable to attack because it has been destroyed..!\033[0;37m" << std::endl;
	}
	else if(this->_ep <= 0)
		std::cout << "\033[0;30mClapTrap " << this->_name << " can't attack " << target << " because he doesn't have enough Energy Points left..!\033[0;37m" << std::endl;
	else
	{		
		std::cout << "\033[1;34mClapTrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage!\033[0;37m" << std::endl;
		this->_ep--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
		std::cout << "\033[1;35mClapTrap " << this->_name << " is already out of Hit Points! Learn when to stop...\033[0;37m" << std::endl;
	else
	{
		std::cout << "\033[1;31mClapTrap " << this->_name << " takes "  << amount << " points of damage!\033[0;37m" << std::endl;
		this->_hp -= amount;
		if (this->_hp <= 0)
		{
			this->_hp = 0;
			std::cout << "\033[1;30mClapTrap " << this->_name << " has been destroyed..!\033[0;37m" << std::endl;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int previous = this->_hp;
	if (this->_hp <= 0)
	{
		std::cout << "\033[0;30mClapTrap " << this->_name << " can't be repaired because it's already beyond repair..!\033[0;37m" << std::endl;
	}
	else if(this->_ep <= 0)
		std::cout << "\033[0;30mClapTrap " << this->_name << " can't be repaired because he doesn't have enough Energy Points left..!\033[0;37m" << std::endl;
	else if (this->_hp >= 100)
		std::cout << "\033[0;30mClapTrap " << this->_name << " is already at max Hit Points, you can't repair something that isn't broken..!\033[0;37m" << std::endl;
	else
	{
		this->_hp += amount;
		this->_ep--;
		if (this->_hp > 100)
			this->_hp = 100;
		std::cout << "\033[1;32mClapTrap " << this->_name << " has recovered "  << this->_hp - previous << " Hit Points!\033[0;37m" << std::endl;
		if (this->_hp == 100)
			std::cout << "\033[1;33mClapTrap " << this->_name << " has been fully repaired, it looks brand new!\033[0;37m" << std::endl;
	}
}
