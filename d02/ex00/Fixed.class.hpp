#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {

    static const int _fracBits = 8;
	int              _fixedPoint;

public:

    Fixed();
    ~Fixed();
    Fixed(Fixed const &rhs);
    Fixed &operator=(Fixed const &rhs);

    int  getRawBits() const;
    void setRawBits(int const raw);
};

#endif