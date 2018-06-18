#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "Dealer.h"
#include <iostream>

class Player
{
private:
    double money;
    char id;
    int player_card[11];
    int player_card_sum;
public:
    Player();
    int count_playerpoints();
    void show_card();
    virtual void add_card(Dealer* dealer);
    void setId(char c);
    char getId();
    void setMoney(double m);
    double getMoney();
    void begin_card();
};


class PlayerA : public Player
{
public:
    PlayerA();
    void add_card(Dealer* dealer);
    void buildId(char c);
    void buildMoney(double m);
};


#endif // PLAYER_H_INCLUDED
