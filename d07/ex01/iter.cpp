#include <iostream>

template<typename T>
void iter(T* arr, int len, void (*fp)(T const&)) {

	if (arr != nullptr) {
		
		for (int i = 0; i < len; i++) {
			fp(arr[i]);
		}
	}
}

template<typename T>
void printIt(T const& x) {

	std::cout << x << std::endl;
}

int main() {

	int numbers[] = {1, 2, 3, 4, 5, 69, 100};
	std::string words[] = {"apple", "banana", "cherry", "durian", "eggplant"};

	iter(numbers, 7, printIt);
	iter(words, 5, printIt);

	return 0;
}
