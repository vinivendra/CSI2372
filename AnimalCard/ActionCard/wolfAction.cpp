
#include "wolfAction.h"

#include <iostream>


using namespace std;


WolfAction::WolfAction() : ActionCard(Animal::WOLF) {
}

QueryResult WolfAction::query() {
    cout << "Please choose the location of a card on the table to add it\n"
            "to your hand.\n";
    int x, y;
    cin >> x >> y;
    return QueryResult(x, y);
}

void WolfAction::perform(Table &table,
                         Player *playerList,
                         QueryResult queryResult) {

    int currentPlayer = gameInfo.currentPlayer;

    int x, y;
    queryResult.getCoordinates(x, y);

    shared_ptr<AnimalCard> chosenCard;

    // Repeat the query until we get a valid position
    while (true) {
        try {
            chosenCard = table.pickAt(y, x);
        } catch (...) {
            cout << "Invalid location, try again." << endl;
            queryResult = query();
            continue;
        }
        break;
    }

    playerList[currentPlayer].yourHand += chosenCard;
}
