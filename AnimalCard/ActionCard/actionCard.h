
#ifndef actionCard_h
#define actionCard_h

#include "../startCard.h"
#include "../../Container/Table/table.h"
#include "../../Container/Player/player.h"
#include "queryResult.h"


struct GameInfo {
    int currentPlayer;
    int numberOfPlayers;
};


class ActionCard : public StartCard {
protected:
    GameInfo gameInfo;

public:
    ActionCard(Animal);

    void printRow(EvenOdd);

    void setGameInfo(GameInfo);

    virtual QueryResult query() = 0;
    virtual void perform(Table &, Player *, QueryResult) = 0;
};

#endif
