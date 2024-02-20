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
    Fixed(int const& src);
    Fixed(float const& src);
    Fixed(Fixed const& src);
    ~Fixed(void);

    Fixed& operator=(Fixed const& rhs);
    bool operator<(Fixed const& rhs);
    bool operator==(Fixed const& rhs);
    bool operator!=(Fixed const& rhs);
    bool operator<=(Fixed const& rhs);
    bool operator>(Fixed const& rhs);
    bool operator>=(Fixed const& rhs);

    Fixed operator*(Fixed const& rhs);
    Fixed operator/(Fixed const& rhs);
    Fixed operator+(Fixed const& rhs);
    Fixed operator-(Fixed const& rhs);
    Fixed operator++( int );
    Fixed operator--( int );
    Fixed& operator++( void );
    Fixed& operator--( void );

    static const Fixed& min(Fixed const& rhs, Fixed const& rhs2);
    static Fixed& min(Fixed& rhs, Fixed& rhs3);
    static const Fixed& max(Fixed const& rhs, Fixed const& rhs2);
    static Fixed& max(Fixed& rhs, Fixed& rhs3);

    int getRawBits( void ) const;
    void setRawBits( int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
