#pragma once
#include <iostream>
#include <string>

class Harl
{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void) ;
        void    error( void );
        void    def( void );
    
    public:
        Harl(void);
        ~Harl(void);
        void    complain( std::string level);
};
