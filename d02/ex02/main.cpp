#include <iostream>
#include "Fixed.class.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << max( a, b ) << std::endl;

    Fixed c(5.73f);

    std::cout << c << std::endl;
    std::cout << c.toInt() << std::endl;

    return 0;
}