
#include "bearAction.h"

#include <iostream>


using namespace std;


BearAction::BearAction() : ActionCard(Animal::BEAR) {
}

QueryResult BearAction::query() {
    cout << "Please choose the number of another player to switch hands with\n"
            "you.\n";
    int x;
    cin >> x;
    return QueryResult(x);
}

void BearAction::perform(Table &table,
                         Player *playerList,
                         QueryResult queryResult) {
    int x;
    queryResult.getPlayer(x);
    x--;    // Correct the index

    int currentPlayer = gameInfo.currentPlayer;

    Hand firstHand = playerList[currentPlayer].yourHand;
    playerList[currentPlayer].yourHand = playerList[x].yourHand;
    playerList[x].yourHand = firstHand;
}
