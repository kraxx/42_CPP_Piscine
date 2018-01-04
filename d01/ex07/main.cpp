#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "stdlib.h"

void errorChecks(std::string s1, std::string s2, std::ifstream input, std::ofstream output) {
    if (s1.length() <= 0 || s2.length() <= 0) {
        std::cerr << "Error: empty string input(s)" << std::endl;
        exit(1);        
    } else if (!input) {
        std::cerr << "Error: invalid file input" << std::endl;
        exit(1);
    } else if (!output) {
        std::cerr << "Error: could not create output" << std::endl;
        exit(1);        
    };
};

void myplace(std::string file, std::string s1, std::string s2) {

    // std::ifstream input(file);
    std::ifstream input;
    input = std::fstream::open(file);
    std::ofstream output(file + ".replace");
    errorChecks(s1, s2, input, output);

    std::string buf;
    buf << input.rdbuf();

    while (buf.find(s1) != std::string::npos) {
        // while (buf.find(s1) != std::string::npos) {
            buf.replace(buf.find(s1), s1.length(), s2);
        // }
    }
    output << buf << std::endl;

    input.close();
    output.close();
};

int main(int ac, char *av[]) {
    if (ac != 4) {
        std::cerr << "usage: ./replace [file] [target string] [replacement string]" << std::endl;
        return 1;
    };
    myReplace(std::string(av[1]), std::string(av[2]), std::string(av[3]));
    return 0;
}