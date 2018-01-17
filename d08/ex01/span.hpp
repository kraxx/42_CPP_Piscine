#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {

private:

	unsigned int     _size;
	std::vector<int> _intArr;

public:

	Span() {};
	Span(unsigned int size);
	Span(Span const& rhs);
	Span& operator=(Span const& rhs);
	~Span() {};

	void 		 addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif