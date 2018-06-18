#ifndef DEALER_H_INCLUDED
#define DEALER_H_INCLUDED

class Dealer
{
private:
    static Dealer* instance;
    double money;
    int dealer_card[11];
    int dealer_card_sum;
    int dealer_points;
    Dealer(double m);
public:
    static Dealer* getInstance(double m);
    //Dealer();
    int count_dealerpoints();
    void show_card();
    int get_dealer_points();
    void show_allcard();
    void begin_card();
    //void bet() {  }
};
/*
class Changer : public Dealer
{
private:
    Dealer* dealer;
public:
    Changer(Dealer* d)
    {

    }
    void bet()
    {
        dealer->bet();
    }
};

class Bet : public Changer
{
public:
    Bet(Dealer* d) : Changer(d)
    {

    }
    void add_money()
    {
        Changer::bet();
    }
};
*/
#endif // DEALER_H_INCLUDED
