#include "setup.h"
#include <iostream>
#include "Dealer.h"
#include "Player.h"
using namespace std;

void setup::game_begin(Player player, Dealer dealer)
{
    cout << "Game begin...\n";
    cout << "��ʼ����...\n";
    player.show_card();
    dealer.show_card();
    cout << "������������1, ";
    cout << "��������2��";
    int t;
    bool flag = true;
    while(cin >> t && flag)
    {
        if (t == 1)
        {
            if (dealer.get_dealer_points() < 17)
                dealer.add_card();
            player.add_card(dealer);
            player.show_card();
            dealer.show_card();
            cout << "������������1, ";
            cout << "��������2��";
        }
        else
        {
            flag = false;
            show_result(player, dealer);
        }
    }
}

void setup::show_result(Player player, Dealer dealer)
{
    if (player.count_playerpoints() > dealer.get_dealer_points())
    {
        cout << "��Ӯ�ˣ�\n";
        dealer.show_allcard();
        game_over();
    }
    else if (player.count_playerpoints() == dealer.get_dealer_points())
    {
        cout << "��ĵ�����ׯ�ҵ�һ��������ׯ��Ӯ�ˣ�\n";
        dealer.show_allcard();
        game_over();
    }
    else
    {
        cout << "�����ˣ�\n";
        dealer.show_allcard();
        game_over();
    }
}

void setup::game_over()
{
    int choice = 0;
    cout << "������Ϸ����1��";
    cout << "�˳���Ϸ����2��";
    cin >> choice;
    if (choice == 1)
    {
        cout << "====================================\n";
        Player player(10);
        Dealer dealer(10);
        game_begin(player, dealer);
    }
    else
    {
        exit(0);
    }
}

