#include <iostream>
#include "setup.h"
#include "Dealer.h"
#include "Player.h"

int main()
{
    setup s;
    Player player(10);
    Dealer dealer(10);
    s.game_begin(player, dealer);
    return 0;
}
