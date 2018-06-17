#include "Player.h"
#include "Card.h"
#include "Dealer.h"
#include "setup.h"

using namespace std;

Player::Player(int m)
{
    Card card;
    money = m;
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
            cout << "������������һ��A��ѡ1����1��ѡ11����2��";
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

Player::~Player()
{
    delete [] player_card;
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
    cout << "����������е�����: ";
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

void Player::add_card(Dealer dealer)
{
    Card card;
    int temp = card.getCardA();
    if (temp > 10)
    {
        player_card[player_card_sum] = 10;
    }
    else if (temp == 1)
    {
        cout << "��������һ��A��ѡ1����1��ѡ11����2��";
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


    if (count_playerpoints() > 21)
    {
        cout << "����Ѿ����ˣ�����\n";
        show_card();
        dealer.show_allcard();
        setup s;
        s.game_over();
    }
    else if (dealer.get_dealer_points() > 21)
    {
        cout << "ׯ���Ѿ����ˣ�\n";
        show_card();
        dealer.show_allcard();
        setup s;
        s.game_over();
    }
}
