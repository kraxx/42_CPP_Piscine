#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class NinjaTrap : public ClapTrap {

public:

    NinjaTrap();
    NinjaTrap(std::string name);
    NinjaTrap(NinjaTrap const& rhs);
    NinjaTrap& operator=(NinjaTrap const& rhs);
    ~NinjaTrap();

    void ninjaShoebox(std::string const& target);
};

#endif