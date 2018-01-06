#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <fstream>

class Logger {

private:
    std::ofstream   _file;

    void            logToConsole(std::string const &msg);
    void            logToFile(std::string const &msg);
    std::string     makeLogEntry(std::string const &msg);

public:
    void        log(std::string const &dest, std::string const &message);
    Logger(std::string file);
    ~Logger();
};

#endif