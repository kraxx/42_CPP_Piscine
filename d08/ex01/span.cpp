#include "span.hpp"
#include <vector>
#include <stdexcept>
#include <limits>

#include <iostream>

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

	int min = INT_MAX;
	int diff;
	std::vector<int>		   tmp = _intArr;
	std::vector<int>::iterator it =  tmp.begin();
	std::vector<int>::iterator it2 = it + 1;
	std::vector<int>::iterator end = tmp.end();
	
	if (tmp.size() > 1) {
		std::sort(tmp.begin(), tmp.end());
		for (; it2 != end; it++, it2++) {
			diff = abs(*it - *it2);
			if (diff > 0 && diff < min) {
				min = diff;
			}
		}
	} else {
		throw std::logic_error("Error: container has 1 or less contents");
	}

	if (min == INT_MAX) {
		return 0;
	} else {
		return min;
	}
}

unsigned int Span::longestSpan() {

	int max;
	int min;

	if (_intArr.size() > 1) {
		max = *std::max_element(_intArr.begin(), _intArr.end());
		min = *std::min_element(_intArr.begin(), _intArr.end());
	} else {
		throw std::logic_error("Error: container has 1 or less contents");
	}
	return (max - min);
}