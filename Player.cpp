#include "Player.h"
#include "Card.h"
#include "Dealer.h"
#include <iostream>

using namespace std;

Player::Player()
{

}

void Player::begin_card()
{
    Card card;
    player_card_sum = 2;
    int temp = card.getCardA();
    if (temp > 10)
    {
        player_card[0] = 10;
    }
    else
    {
        player_card[0] = temp;
    }
    temp = card.getCardB();
    if (temp > 10)
    {
        player_card[1] = 10;
    }
    else
    {
        player_card[1] = temp;
    }
    for (int i = 0; i < 2; ++i)
    {
        if (player_card[i] == 1)
        {
            show_card();
            cout << "所以你现在有一个A，选1输入1，选11输入2：";
            int t2;
            cin >> t2;
            if (t2 == 1)
            {
                player_card[i] = 1;
            }
            else
            {
                player_card[i] = 11;
            }
        }
    }
}

int Player::count_playerpoints()
{
    int playerpoints = 0;
    for (int i = 0; i < player_card_sum; i++)
    {
        playerpoints = playerpoints + player_card[i];
    }
    return playerpoints;
}

void Player::show_card()
{
    cout << "现在" << getId() << "玩家手中的牌是: ";
    for (int i = 0; i < player_card_sum; ++i)
    {
        if (player_card[i] == 1)
            cout << "A ";
        else if (player_card[i] == 11)
            cout << "J ";
        else if (player_card[i] == 12)
            cout << "Q ";
        else if (player_card[i] == 13)
            cout << "K ";
        else
            cout << player_card[i] << ' ';
    }
    cout << endl;
}

void Player::add_card(Dealer* dealer)
{
    Card card;
    int temp = card.getCardA();
    if (temp > 10)
    {
        player_card[player_card_sum] = 10;
    }
    else if (temp == 1)
    {
        cout << "你现在有一个A，选1输入1，选11输入2：";
        int t2;
        cin >> t2;
        if (t2 == 1)
        {
            player_card[player_card_sum] = 1;
        }
        else
        {
            player_card[player_card_sum] = 11;
        }
    }
    else
    {
        player_card[player_card_sum] = temp;
    }
    player_card_sum++;
}

void Player::setId(char c)
{
    id = c;
}

char Player::getId()
{
    return id;
}

void Player::setMoney(double m)
{
    money = m;
}

double Player::getMoney()
{
    return money;
}



PlayerA::PlayerA() : Player()
{

}

void PlayerA::add_card(Dealer* dealer)
{
    Player::add_card(dealer);
    if (count_playerpoints() > 21)
    {
        cout << "玩家A已经爆了！！！\n";
        show_card();
        (*dealer).show_allcard();
        exit(0);
    }
    else if ((*dealer).get_dealer_points() > 21)
    {
        cout << "庄家已经爆了！\n";
        show_card();
        (*dealer).show_allcard();
        exit(0);
    }
}

void PlayerA::buildId(char c)
{
    Player::setId(c);
}

void PlayerA::buildMoney(double m)
{
    Player::setMoney(m);
}
