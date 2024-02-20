#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
private:
    int _integer;
    static const int _fract = 8;
public:
    Fixed(void);
    Fixed(Fixed const& src);
    ~Fixed(void);
    Fixed& operator=(Fixed const& rhs);
    int getRawBits( void ) const;
    void setRawBits( int const raw);
};

#endif
