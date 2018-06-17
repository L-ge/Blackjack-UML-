#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

#include <iostream>
using namespace std;

class Dealer
{
private:
    double money;
    int dealer_card[11];
    int dealer_card_sum;
    int dealer_points;
public:
    Dealer(int m);
    int count_dealerpoints();
    void show_card();
    int get_dealer_points();
    void add_card();
    void show_allcard();
};

#endif // DEALER_H_INCLUDED
