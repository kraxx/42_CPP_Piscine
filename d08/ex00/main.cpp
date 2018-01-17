#include <iostream>
#include <list>
#include "easyfind.hpp"

int main() {

	std::list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	// int arr[] = {1, 2, 3, 4, 5, 6, 7};

	std::list<int> ret =  easyfind(list, 2);

	std::cout << ret << std::endl;

	return 0;
}