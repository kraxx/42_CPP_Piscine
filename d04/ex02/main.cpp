#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISquad* vlc = new Squad;

    vlc->push(bob);
    vlc->push(jim);

    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    delete vlc;

    ISquad*       UNDERWATER_SQUAD = new Squad;

    ISpaceMarine* dolphins[10];
    for (int i = 0; i < 10; i++) {
        dolphins[i] = new TacticalMarine;
        UNDERWATER_SQUAD->push(dolphins[i]);
    }

    ISpaceMarine* stingrays[10];
    for (int i = 0; i < 10; i++) {
        stingrays[i] = new AssaultTerminator;
        UNDERWATER_SQUAD->push(dolphins[i]);
    }

    for (int i = 0; i < UNDERWATER_SQUAD->getCount(); ++i)
    {
        ISpaceMarine* cur = UNDERWATER_SQUAD->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete UNDERWATER_SQUAD;

    return 0;
}