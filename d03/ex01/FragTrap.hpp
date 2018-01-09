#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>

class FragTrap {

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

    FragTrap();
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(FragTrap const& rhs);
    FragTrap& operator=(FragTrap const& rhs);

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);    
    void vaulthunter_dot_exe(std::string const& target);
};

#endif