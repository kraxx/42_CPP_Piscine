#include <iostream>
#include "span.hpp"

int main() {

	Span sp(10);

	sp.addNumber(1);
	sp.addNumber(5);
	sp.addNumber(9);
	sp.addNumber(7);
	sp.addNumber(5);
	sp.addNumber(6);
	sp.addNumber(5);
	sp.addNumber(6);
	sp.addNumber(5);
	sp.addNumber(6);

	// sp.addNumber(1);
	// sp.addNumber(1);
	// sp.addNumber(1);
	// sp.addNumber(1);

	std::cout << sp.longestSpan() << std::endl;


}