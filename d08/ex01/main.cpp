#include <iostream>
#include "span.hpp"

int main() {

	Span sp(10);

	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
	sp.addNumber(5);
	sp.addNumber(6);
	sp.addNumber(7);
	sp.addNumber(8);
	sp.addNumber(9);
	sp.addNumber(10);

	// sp.addNumber(1);
	// sp.addNumber(5);
	// sp.addNumber(9);
	// sp.addNumber(7);
	// sp.addNumber(5);
	// sp.addNumber(6);
	// sp.addNumber(5);
	// sp.addNumber(6);
	// sp.addNumber(5);
	// sp.addNumber(6);

	// sp.addNumber(1);
	// sp.addNumber(1);
	// sp.addNumber(1);
	// sp.addNumber(1);
	// sp.addNumber(1);
	// sp.addNumber(1);
	// sp.addNumber(1);

	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;


	Span xd(50);
	try {
		for (int i = 0; i < 1000; i++) {
			xd.addNumber(i);
			std::cout << "adding to xd: " << i << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}