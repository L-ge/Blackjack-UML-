#ifndef SETUP_H_INCLUDED
#define SETUP_H_INCLUDED
#include "Dealer.h"
#include "Player.h"
class setup
{
public:
    void game_begin(Player player, Dealer dealer);
    void game_over();
    void show_result(Player player, Dealer dealer);
};

#endif // SETUP_H_INCLUDED
