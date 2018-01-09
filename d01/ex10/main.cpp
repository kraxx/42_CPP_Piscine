#include <iostream>
#include <fstream>
#include <cerrno>

int  main(int ac, char *av[]) {

    if (ac == 1) {
        std::cout << std::cin.rdbuf();
        return 0;
    }
    for (int i = 1; i < ac; i++) {

        std::string input(av[i]);

        if (input == "-" || input == "--") {
            std::cout << std::cin.rdbuf();
        } else {

            std::ifstream inputStream(input);

            if (!errno) {
                std::cout << inputStream.rdbuf();
            } else {
                std::cout << "cato9tails: " << std::strerror(errno) << std::endl;
            }
        }
    }
    return 0;
}
