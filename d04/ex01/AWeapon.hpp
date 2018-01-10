#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>

class AWeapon {

protected:
    
    std::string _name;
    int         _apcost;
    int         _damage;

    AWeapon();

public:

    AWeapon(std::string const& name, int apcost, int damage);
    AWeapon(AWeapon const& rhs);
    AWeapon& operator=(AWeapon const& rhs);
    virtual  ~AWeapon();

    std::string  getName() const;
    int          getAPCost() const;
    int          getDamage() const;

    virtual void attack() const = 0;
};

#endif