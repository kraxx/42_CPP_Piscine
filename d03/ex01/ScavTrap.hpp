#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

class ScavTrap {

    static bool  _seeded;
    std::string  _name;
    unsigned int _HP;
    unsigned int _maxHP;
    unsigned int _EP;
    unsigned int _maxEP;
    unsigned int _level;
    unsigned int _meleeAtkDmg;
    unsigned int _rangedAtkDmg;
    unsigned int _armor;

public:

    ScavTrap();
    ScavTrap(std::string name);
    ~ScavTrap();
    ScavTrap(ScavTrap const& rhs);
    ScavTrap& operator=(ScavTrap const& rhs);

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);    
    void challengeNewcomer(std::string const& target);
};

#endif