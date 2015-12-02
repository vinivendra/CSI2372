
#ifndef actionCard_h
#define actionCard_h

#include "../startCard.h"
#include "../../Container/Table/table.h"
#include "../../Container/Player/player.h"
#include "queryResult.h"


class ActionCard : public StartCard {
protected:
    int currentPlayer;
public:
    ActionCard(Animal);

    void printRow(EvenOdd);

    void setCurrentPlayer(int);

    virtual QueryResult query() = 0;
    virtual void perform(Table &, Player *, QueryResult) = 0;
};

#endif
