
#include "mooseAction.h"

#include <iostream>


using namespace std;


MooseAction::MooseAction() : ActionCard(Animal::MOOSE) {
}

QueryResult MooseAction::query() {
    return QueryResult();
}

void MooseAction::perform(Table &table,
                         Player *playerList,
                         QueryResult queryResult) {
    int numberOfPlayers = gameInfo.numberOfPlayers;

    Hand lastHand = playerList[numberOfPlayers - 1].yourHand;

    for (int current = numberOfPlayers - 1; current > 0; current--) {
        int previous = current - 1;
        playerList[current].yourHand = playerList[previous].yourHand;
    }

    playerList[0].yourHand = lastHand;
}
