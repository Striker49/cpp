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
    Fixed(Fixed const& src);
    ~Fixed(void);
    Fixed& operator=(Fixed const& rhs);
    int getRawBits( void ) const;
    void setRawBits( int const raw);
};

#endif
