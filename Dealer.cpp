#include "Dealer.h"
#include "Card.h"
#include <iostream>
using namespace std;

Dealer* Dealer::getInstance(double m)
{
    Dealer* instance = new Dealer(m);
    return instance;
}

Dealer::Dealer(double m)
{
    money = m;
}

void Dealer::begin_card()
{
    Card card;
    dealer_card_sum = 0;
    dealer_points = 0;
    int temp = card.getCardA();
    while (dealer_points < 17)
    {
        temp = card.getCardC(temp);
        if (temp > 10)
        {
            dealer_card[dealer_card_sum] = 10;
            dealer_points += 10;
        }
        else if (temp == 1)
        {
            int t1 = rand() % 2;
            if (t1 == 1 && dealer_points <= 11)
            {
                dealer_card[dealer_card_sum] = 11;
                dealer_points += 11; // ��AΪ10.
            }
            else
            {
                dealer_card[dealer_card_sum] = 1;
                dealer_points += 1; // ��AΪ1.
            }
        }
        else
        {
            dealer_card[dealer_card_sum] = temp;
            dealer_points += temp;
        }
        dealer_card_sum++;
    }
}

void Dealer::show_card()
{
    cout << "����ׯ�����п���ʾ������: ";
    for (int i = 1; i < dealer_card_sum; ++i)
    {
        if (dealer_card[i] == 1)
            cout << "A ";
        else if (dealer_card[i] == 11)
            cout << "J ";
        else if (dealer_card[i] == 12)
            cout << "Q ";
        else if (dealer_card[i] == 13)
            cout << "K ";
        else
            cout << dealer_card[i] << ' ';
    }
    cout << endl;
}

void Dealer::show_allcard()
{
    cout << "ׯ�����е�����: ";
    for (int i = 0; i < dealer_card_sum; ++i)
    {
        if (dealer_card[i] == 1)
            cout << "A ";
        else if (dealer_card[i] == 11)
            cout << "J ";
        else if (dealer_card[i] == 12)
            cout << "Q ";
        else if (dealer_card[i] == 13)
            cout << "K ";
        else
            cout << dealer_card[i] << ' ';
    }
    cout << endl;
}

int Dealer::get_dealer_points()
{
    return dealer_points;
}
