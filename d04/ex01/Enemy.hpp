#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy {

protected:
    
    int         _hp;
    std::string _type;

    Enemy();

public:

    Enemy(int hp, std::string const& type);
    Enemy(Enemy const& rhs);
    Enemy&  operator=(Enemy const& rhs);
    virtual ~Enemy();

    std::string  getType() const;
    int          getHP() const;

    virtual void takeDamage(int damage);
};

#endif