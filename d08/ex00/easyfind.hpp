#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template<typename T>
T& easyfind(T list, int n) {

	typename T::iterator it;

	try {
		it = std::find(list.begin(), list.end(), n);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	if (it == list.end())
		return nullptr;
	return it;
}

#endif