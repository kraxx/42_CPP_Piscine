#include <cmath>
#include <iostream>
#include <string>
#include "Fixed.class.hpp"

//Canonical member functions

Fixed::Fixed() : 
_fixedPoint(0) {};

Fixed::Fixed(int const n) :
_fixedPoint(n << _fracBits) {};

Fixed::Fixed(float const n) :
_fixedPoint(roundf(n * (1 << _fracBits))) {};

Fixed::~Fixed() {};

Fixed::Fixed(Fixed const& rhs) {
    *this = rhs;
};

//Operator overloads

Fixed&  Fixed::operator=(Fixed const& rhs) {
    _fixedPoint = rhs.getRawBits();
    return *this;
};

bool    Fixed::operator>(Fixed const& rhs) const {
    return (_fixedPoint > rhs.getRawBits());
};

bool    Fixed::operator<(Fixed const& rhs) const {
    return (_fixedPoint < rhs.getRawBits());
};

bool    Fixed::operator>=(Fixed const& rhs) const {
    return (_fixedPoint >= rhs.getRawBits());
};

bool    Fixed::operator<=(Fixed const& rhs) const {
    return (_fixedPoint <= rhs.getRawBits());
};

bool    Fixed::operator==(Fixed const& rhs) const {
    return (_fixedPoint == rhs.getRawBits());
};

bool    Fixed::operator!=(Fixed const& rhs) const {
    return (_fixedPoint != rhs.getRawBits());
};

Fixed   Fixed::operator+(Fixed const& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
};

Fixed   Fixed::operator-(Fixed const& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
};

Fixed   Fixed::operator*(Fixed const& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
};

Fixed   Fixed::operator/(Fixed const& rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
};

Fixed&  Fixed::operator++() {
    _fixedPoint++;
    return *this;
};

Fixed&  Fixed::operator--() {
    _fixedPoint--;
    return *this;
};

Fixed   Fixed::operator++(int) {
    Fixed ret = *this;
    ++*this;
    return ret;
};

Fixed   Fixed::operator--(int) {
    Fixed ret = *this;
    --*this;
    return ret;

};

//Other member functions

int Fixed::getRawBits() const {
    return _fixedPoint;
};

void Fixed::setRawBits(int const raw) {
    _fixedPoint = raw;
};

float Fixed::toFloat() const {
    return (float)_fixedPoint / (1 << _fracBits);
};

int Fixed::toInt() const {

    int x = _fixedPoint;

    x >>= _fracBits - 1;
    x += x % 2;
    return x >> 1;
};

//Non-member functions

std::ostream& operator<<(std::ostream &output, Fixed const &rhs) {
    output << rhs.toFloat();
    return output;
};

Fixed&        min(Fixed& f1, Fixed &f2) {
    if (f1 < f2) {
        return f1;
    }
    return f2;
};

Fixed&        max(Fixed& f1, Fixed& f2) {
    if (f1 > f2) {
        return f1;
    }
    return f2;
};

const Fixed&  min(Fixed const& f1, Fixed const& f2) {
    if (f1 < f2) {
        return f1;
    }
    return f2;    
};


const Fixed&  max(Fixed const& f1, Fixed const& f2) {
    if (f1 > f2) {
        return f1;
    }
    return f2;    
};
