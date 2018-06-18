#include <iostream>
#include "Dealer.h"
#include "Player.h"
#include <iostream>
using namespace std;

void game_begin(Player & player, Dealer* dealer);
void show_result(Player player, Dealer* dealer);

void game_begin(Player & player, Dealer* dealer)
{
    player.show_card();
    (*dealer).show_card();
    cout << "������������1, ";
    cout << "��������2��";
    int t;
    bool flag = true;
    while(cin >> t && flag)
    {
        if (t == 1)
        {
            player.add_card(dealer);
            player.show_card();
            (*dealer).show_card();
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

void show_result(Player player, Dealer* dealer)
{
    if (player.count_playerpoints() > (*dealer).get_dealer_points())
    {
        cout << "��Ӯ�ˣ�\n";
        (*dealer).show_allcard();
        exit(0);
    }
    else if (player.count_playerpoints() == (*dealer).get_dealer_points())
    {
        cout << "��ĵ�����ׯ�ҵ�һ��������ׯ��Ӯ�ˣ�\n";
        (*dealer).show_allcard();
        exit(0);
    }
    else
    {
        cout << "�����ˣ�\n";
        (*dealer).show_allcard();
        exit(0);
    }
}


int main()
{
    cout << "Game begin...\n";
    cout << "��ʼ����...\n";
    PlayerA* playerA = new PlayerA();
    playerA->buildId('A');
    playerA->buildMoney(10);
    playerA->begin_card();
    Player & player = (*playerA);
    Dealer* dealer = Dealer::getInstance(10);
    dealer->begin_card();
    game_begin(player, dealer);
    delete dealer;
    return 0;
}
