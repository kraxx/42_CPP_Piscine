#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

class ImpossibleException : public std::exception {

public:

	virtual const char* what() const throw() {
		return "impossible";
	};
};

class NonDisplayableException : public std::exception {

public:

	virtual const char* what() const throw() {
		return "non displayable";
	};
};

int getPrecision(char *s) {

	unsigned int i = 0;
	unsigned int j;

	while (s[i] != 0 && s[i] != '.') {
		i++;
	}
	if (strlen(s) == i) {
		return 1;
	}
	j = i + 1;
	while (s[j] != 0 && isdigit(s[j])) {
		j++;
	}
	j -= i;
	if (j == 1) {
		return 1;
	} else {
		return (j - 1);
	}
}

void printChar(double d) {

	try {

		char c;
		
		std::cout << "char: ";
		
		if (isnan(d) == true) {
			throw ImpossibleException();
		}

		c = static_cast<char>(d);
		
		if (std::isprint(c) == false) {
			throw NonDisplayableException();
		}

		std::cout << c << std::endl;
	
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void printInt(double d) {

	try {

		int i;

		std::cout << "int: ";
		if (isinf(d) == true
			|| isnan(d) == true
			|| d > static_cast<int>(INT_MAX)
			|| d < static_cast<int>(INT_MIN)) {

			throw ImpossibleException();
		}
		i = static_cast<int>(d);

		std::cout << i << std::endl;

	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void printFloat(double d, int p) {
	std::cout << "float: " << std::setprecision(p) << std::fixed << static_cast<float>(d) << "f" << std::endl;
}

void printDouble(double d, int p) {
	std::cout << "double: " << std::setprecision(p) << std::fixed << static_cast<double>(d) << std::endl;	
}

int main(int ac, char* av[]) {

	if (ac != 2) {
		std::cout << "Usage: " << av[0] << " [data]" << std::endl;
		return 0;
	}

	double d = std::atof(av[1]);
	int    p = getPrecision(av[1]);

	if (d == 0 && *av[1] != '0') {
		std::cout << "NaN" << std::endl;
		return 0;
	}

	printChar(d);
	printInt(d);
	printFloat(d, p);
	printDouble(d, p);

	return 0;



}
