#include "Dealer.h"
#include "Card.h"
#include "setup.h"

Dealer::Dealer(int m)
{
    Card card;
    money = m;
    dealer_card_sum = 2;
    dealer_points = 0;

    int temp = card.getCardB();
    if (temp > 10)
    {
        dealer_card[0] = 10;
        dealer_points += 10;
    }
    else if (temp == 1)
    {
        int t1 = rand() % 2;
        if (t1 == 1 && dealer_points <= 11)
        {
            dealer_card[0] = 11;
            dealer_points += 11; // 即A为10.
        }
        else
        {
            dealer_card[0] = 1;
            dealer_points += 1; // 即A为1.
        }
    }
    else
    {
        dealer_card[0] = temp;
        dealer_points += temp;
    }

    temp = card.getCardA();
    if (temp > 10)
    {
        dealer_card[1] = 10;
        dealer_points += 10;
    }
    else if (temp == 1)
    {
        int t1 = rand() % 2;
        if (t1 == 1 && dealer_points <= 11)
        {
            dealer_card[1] = 11;
            dealer_points += 11; // 即A为10.
        }
        else
        {
            dealer_card[1] = 1;
            dealer_points += 1; // 即A为1.
        }
    }
    else
    {
        dealer_card[1] = temp;
        dealer_points += temp;
    }

}

void Dealer::show_card()
{
    cout << "现在庄家手中可显示的牌是: ";
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
    cout << "庄家手中的牌是: ";
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

void Dealer::add_card()
{
    while (get_dealer_points() < 17)
    {
        Card card;
        int temp = card.getCardA();
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
                dealer_points += 11; // 即A为10.
                dealer_card[dealer_card_sum] = 11;
            }
            else
            {
                dealer_points += 1; // 即A为1.
                dealer_card[dealer_card_sum] = 1;
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

int Dealer::get_dealer_points()
{
    return dealer_points;
}
