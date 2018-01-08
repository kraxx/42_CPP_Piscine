#include <cmath>
#include <iostream>
#include <string>
#include "Fixed.class.hpp"

Fixed::Fixed() : 
_fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const n) :
_fixedPoint(n << _fracBits) {
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(float const n) :
_fixedPoint(roundf(n * (1 << _fracBits))) {
    std::cout << "Float constructor called" << std::endl;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(Fixed const &rhs) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
};

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    _fixedPoint = rhs.getRawBits();
    return *this;
};

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
    return _fixedPoint >> _fracBits;
};

std::ostream &operator<<(std::ostream &output, Fixed const &rhs) {
    output << rhs.toFloat();
    return output;
};