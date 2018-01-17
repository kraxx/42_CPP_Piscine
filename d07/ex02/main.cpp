#include "Array.class.tpp"

int main() {

	Array<int> intArr(5);

	std::cout << "Size: " << intArr.size() << std::endl;

	for (unsigned int i = 0; i < intArr.size(); i++) {
		intArr[i] = i + 1;
		std::cout << intArr[i] << std::endl;
	}

	Array<std::string> strArr(5);
	std::string words[] = {"Adam", "Barry", "Carl", "Dana", "Eleanor", "Fran"};
	
	try {

		for (unsigned int i = 0; i < 6; i++) {
			strArr[i] = words[i];
			std::cout << strArr[i] << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}