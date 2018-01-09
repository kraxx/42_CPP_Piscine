#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const& rhs);
    FragTrap& operator=(FragTrap const& rhs);
    ~FragTrap();

    void vaulthunter_dot_exe(std::string const& target);
};

#endif