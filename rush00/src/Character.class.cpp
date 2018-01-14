class Game {

private:

    Player* _player;

};


class Character {

protected:

    unsigned int _hp;
    unsigned int _dmg;
    int          _x;
    int          _y;

    Character();

public:

    virtual ~Character();

    // Getters

    unsigned int getHP() {
        return _hp;
    };

    unsigned int getDmg() {
        return _dmg;
    };

    virtual Bullet& shootBullet();

};


class Player : public Character {

private:

    unsigned int _lives;

public:

    void    B

};


class Enemy : public Character {

private:

    unsigned int _speed;    

public:

};


class Bullet {

private:

    unsigned int _dmg;
    unsigned int _speed;
    bool         _friendly;

public:

    unsigned int getDmg();
    unsigned int getSpeed();
    unsigned int getFriendly();

    void         collide();

};