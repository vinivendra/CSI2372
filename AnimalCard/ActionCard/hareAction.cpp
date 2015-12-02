
#include "hareAction.h"


#include <iostream>


using namespace std;


HareAction::HareAction() : ActionCard(Animal::HARE) {
}

QueryResult HareAction::query() {
    cout << "Please choose the location of the card you want to move.\n";
    int x, y;
    cin >> x >> y;
    cout << "Please choose the card's new location.\n";
    int w, z;
    cin >> w >> z;
    return QueryResult(x, y, w, z);
}

void HareAction::perform(Table &gameBoard,
                         Player *playerList,
                         QueryResult queryResult) {

    int x1, y1, x2, y2;
    queryResult.getCoordinates(x1, y1);
    queryResult.getSecondCoordinates(x2, y2);

    shared_ptr<AnimalCard> chosenCard = nullptr;

    // Repeat the query until we get a valid position
    while (true) {
        try {
            chosenCard = gameBoard.pickAt(y1, x1);
            gameBoard.addAt(chosenCard, y2, x2);
        } catch (...) {
            if (chosenCard != nullptr) {
                gameBoard.addAt(chosenCard, y1, x1);
                chosenCard = nullptr;
            }

            cout << "Invalid location, try again." << endl;
            queryResult = query();
            queryResult.getCoordinates(x1, y1);
            queryResult.getSecondCoordinates(x2, y2);
            continue;
        }
        break;
    }
}
