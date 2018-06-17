#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Dealer.h"
#include <iostream>

class Player
{
private:
    double money;
    int player_card[11];
    int player_card_sum;
public:
    Player(int m);
    ~Player();
    int count_playerpoints();
    void show_card();
    void add_card(Dealer dealer);
};


/*
class PlayerA : public Player
{
public:
    void set_money(double money);
};
*/

#endif // PLAYER_H_INCLUDED
