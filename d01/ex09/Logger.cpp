#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "Logger.hpp"

Logger::Logger(std::string file) :
_file(file, std::ios_base::app) {
    if (!_file) {
        std::cerr << "Error in accessing/creating logfile" << std::endl;
        exit(1);
    }
};

Logger::~Logger() {};

void        Logger::logToConsole(std::string const &msg) {
    std::cout << msg << std::endl;
};

void        Logger::logToFile(std::string const &msg) {
    _file << msg << std::endl;
};

std::string Logger::makeLogEntry(std::string const &msg) {

    time_t t = time(0);
    struct tm *now = localtime(&t); 
	std::stringstream logEntryStream;

    logEntryStream << "[" << (now->tm_year + 1900) << "-"
         << std::setw(2) << std::setfill('0') << (now->tm_mon + 1) << "-"
         << std::setw(2) << std::setfill('0') << now->tm_mday << " "
		 << std::setw(2) << std::setfill('0') << now->tm_hour << ":"
		 << std::setw(2) << std::setfill('0') << now->tm_min << ":"
		 << std::setw(2) << std::setfill('0') << now->tm_sec
		 << "] ";
	return (logEntryStream.str() + msg);
};

void        Logger::log(std::string const &dest, std::string const &message) {

    void (Logger::*fp[2])(std::string const &msg) = {
        &Logger::logToConsole,
        &Logger::logToFile
    };

    const std::string logEntry = Logger::makeLogEntry(message);

    if (dest == "console") {
        (this->*fp[0])(logEntry);
    } else if (dest == "file") {
        (this->*fp[1])(logEntry);
    }
};
