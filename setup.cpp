#include "setup.h"
#include <iostream>
#include "Dealer.h"
#include "Player.h"
using namespace std;

void setup::game_begin(Player player, Dealer dealer)
{
    cout << "Game begin...\n";
    cout << "开始发牌...\n";
    player.show_card();
    dealer.show_card();
    cout << "继续发牌输入1, ";
    cout << "开牌输入2：";
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
            cout << "继续发牌输入1, ";
            cout << "开牌输入2：";
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
        cout << "你赢了！\n";
        dealer.show_allcard();
        game_over();
    }
    else if (player.count_playerpoints() == dealer.get_dealer_points())
    {
        cout << "你的点数和庄家的一样，所以庄家赢了！\n";
        dealer.show_allcard();
        game_over();
    }
    else
    {
        cout << "你输了！\n";
        dealer.show_allcard();
        game_over();
    }
}

void setup::game_over()
{
    int choice = 0;
    cout << "继续游戏输入1：";
    cout << "退出游戏输入2：";
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

