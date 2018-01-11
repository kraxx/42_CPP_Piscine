#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad {

private:

    struct _marine {
        ISpaceMarine*   unit;
        struct _marine* next;
    };
    struct _marine*     _list;
    int                 _listSize;

public:

    Squad();
    Squad(Squad const& rhs);
    Squad& operator=(Squad const& rhs);
    ~Squad();

    int           getCount() const;
    int           push(ISpaceMarine* unit);
    bool          checkDupe(ISpaceMarine* unit);
    ISpaceMarine* getUnit(int n) const;
};

#endif