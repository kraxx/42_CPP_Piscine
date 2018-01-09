#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

protected:

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

    ClapTrap();
    ClapTrap(ClapTrap const& rhs);
    ClapTrap& operator=(ClapTrap const& rhs);
    virtual ~ClapTrap();

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif