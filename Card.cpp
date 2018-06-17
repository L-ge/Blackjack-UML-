#include "Card.h"
#include <windows.h>
#include "time.h"

int Card::getCardA()
{
    srand(GetTickCount());
    return rand() % 13 + 1;
}

int Card::getCardB()
{
    srand((unsigned)time(NULL));
    return rand() % 13 + 1;
}

