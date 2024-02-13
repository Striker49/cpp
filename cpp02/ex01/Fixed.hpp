#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
private:
    int integer;
    static const int fract = 8;
public:
    Fixed(void);
    Fixed(int const& src);
    Fixed(float const& src);
    Fixed(Fixed const& src);
    ~Fixed(void);
    Fixed& operator=(Fixed const& rhs);
    int getRawBits( void ) const;
    void setRawBits( int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
