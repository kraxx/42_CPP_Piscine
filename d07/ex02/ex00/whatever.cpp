#include <iostream>

template<typename T>
void swap(T& a, T& b) {

	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b) {

	if (a < b)
		return a;
	return b;
}

template<typename T>
T const& max(T const& a, T const& b) {

	if (a > b)
		return a;
	return b;
}

int main() {
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		int a = 1, b = 2;
		std::cout << "a: " << a << "; b: " << b << std::endl;
		::swap(a, b);
		std::cout << "swap: a: " << a << "; b: " << b << std::endl;

		std::string s1 = "Wingdings";
		std::string s2 = "Dingaling";

		std::cout << "Max of " << s1 << " & " << s2 << ": " << ::max(s1, s2) << std::endl;
		std::cout << "Min of " << s1 << " & " << s2 << ": " << ::min(s1, s2) << std::endl;

		::swap(s1, s2);

		std::cout << "swap: s1: " << s1 << "; s2: " << s2 << std::endl;
	}
	return 0;
}