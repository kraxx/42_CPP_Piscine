#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>

template<typename T>
int easyfind(T& list, int n) {

	typename T::iterator it;

	try {
		it = std::find(list.begin(), list.end(), n);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	if (it == list.end())
		throw std::logic_error("Item not found in list");
	return *it;
}

#endif