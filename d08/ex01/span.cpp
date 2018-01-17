#include "span.hpp"
#include <vector>
#include <stdexcept>
#include <numeric>
// #include <algorithm>
// #include <list>

Span::Span(unsigned int size):
_size(size) {
	_intArr.reserve(size);
}

Span::Span(Span const& rhs) {
	*this = rhs;
}

Span& Span::operator=(Span const& rhs) {
	_intArr = rhs._intArr;
	return *this;
}

void 		 Span::addNumber(int n) {

	if (_intArr.size() < _size) {
		_intArr.push_back(n);
	} else {
		throw std::length_error("Error: container is at capacity");
	}

}

unsigned int Span::shortestSpan() {

	std::vector<int>::iterator max;
	std::vector<int>::iterator min;
	std::vector<int> 		   tmp;


	if (_intArr.size() > 1) {
		tmp = _intArr;

		
		max = std::max_element(_intArr.begin(), _intArr.end());
		min = std::min_element(_intArr.begin(), _intArr.end());
	} else {
		throw std::logic_error("Error: container has 1 or less contents");
	}
	return std::distance(max, min);
}

unsigned int Span::longestSpan() {

	std::vector<int>::iterator max;
	std::vector<int>::iterator min;
	std::vector<int> 		   tmp;

	if (_intArr.size() > 1) {
		tmp = _intArr;
		std::sort(tmp.begin(), tmp.end());
		max = std::max_element(tmp.begin(), tmp.end());
		min = std::min_element(tmp.begin(), tmp.end());
	} else {
		throw std::logic_error("Error: container has 1 or less contents");
	}
	return std::distance(min, max);
}