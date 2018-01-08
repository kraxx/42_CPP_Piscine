#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

    static const int _fracBits = 8;
	int              _fixedPoint;

public:

    Fixed();
    Fixed(int const n);
    Fixed(float const n);
    ~Fixed();
    Fixed(Fixed const &rhs);
    Fixed        &operator=(Fixed const &rhs);

    int   getRawBits() const;
    void  setRawBits(int const raw);
    float toFloat() const;
    int   toInt() const;
};

std::ostream &operator<<(std::ostream &output, Fixed const &rhs);

#endif