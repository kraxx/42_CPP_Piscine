#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

    static const int _fracBits = 8;
	int              _fixedPoint;

public:

    //Canonical member functions

    Fixed();
    Fixed(int const n);
    Fixed(float const n);
    ~Fixed();
    Fixed(Fixed const& rhs);

    //Operator overloads

    Fixed&    operator=(Fixed const& rhs);
    bool      operator>(Fixed const& rhs) const;
    bool      operator<(Fixed const& rhs) const;
    bool      operator>=(Fixed const& rhs) const;
    bool      operator<=(Fixed const& rhs) const;
    bool      operator==(Fixed const& rhs) const;
    bool      operator!=(Fixed const& rhs) const;
    Fixed     operator+(Fixed const& rhs) const;
    Fixed     operator-(Fixed const& rhs) const;
    Fixed     operator*(Fixed const& rhs) const;
    Fixed     operator/(Fixed const& rhs) const;
    Fixed&    operator++();
    Fixed&    operator--();
    Fixed     operator++(int);
    Fixed     operator--(int);

    //Other member functions

    int       getRawBits() const;
    void      setRawBits(int const raw);
    float     toFloat() const;
    int       toInt() const;
};

//Non-member functions

std::ostream& operator<<(std::ostream &output, Fixed const &rhs);
Fixed&        min(Fixed& f1, Fixed& f2);
Fixed&        max(Fixed& f1, Fixed& f2);
const Fixed&  min(Fixed const& f1, Fixed const& f2);
const Fixed&  max(Fixed const& f1, Fixed const& f2);

#endif