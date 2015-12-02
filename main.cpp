// TODO: Implement AnimalCard's print functions (and subclasses too)
// TODO: Make sure everything that can be const is const
// TODO: Make sure everything that can be private or protected is too
// TODO: Make sure there are no useless re-declarations and re-implementations
// TODO: Implement Table operators
// TODO: Add action cards, no splits, etc. to the animal factory

#include <iostream>

#include "AnimalCard/animalCard.h"
#include "AnimalCard/ActionCard/actionCard.h"
#include "Container/Table/table.h"
#include "Container/AnimalCardFactory/AnimalCardFactory.h"
#include "Container/Player/player.h"
#include "Container/Deck/deck.h"

#include <vector>

using namespace std;


int main(int argc, const char *argv[]) {

    // Game loop

    cout << "How many players are playing? (2-5 players) ";
    int i = 0;
    while (i == 0) {
        cin >> i;
    }
    cout << endl;

    AnimalCardFactory *factory = AnimalCardFactory::getFactory();

    Player *playerList = new Player[i];

    string name;

    for (int j = 0; j != i; j++) {
        cout << "Name of player " << j + 1 << ": ";
        cin >> name;
        playerList[j].setName(name);
        cout << endl;
    }
    // Or load from file

    bool playerHasWon = false;
    Table gameBoard;
    int nbdraws[5]{0, 0, 0, 0, 0};

    while (!playerHasWon) {
        // If pause save game to file and exit
        for (int k = 0; k != i; k++) {

            cout << "Table: " << endl;
            gameBoard.print();

            for (int n = 0; n != nbdraws[k]; n++)
                playerList[k].yourHand += factory->getDeck().draw();

            cout << "Player: " << playerList[k].getName() << endl;
            cout << playerList[k] << endl;

            int c, x, y;

            shared_ptr<AnimalCard> chosenCard = nullptr;

            while (true) {
                try {
                    c = -1;

                    cout << "Which card do you want to play? ";

                    while (c < 0 || c > playerList[k].yourHand.noCards() - 1)
                        cin >> c;

                    int orientation = -1;
                    cout << "Should the card's orientation be reversed? [0/1] ";
                    while (orientation != 0 && orientation != 1)
                        cin >> orientation;

                    cout << endl;
                    cout << "Where do you want to play it? \nX coordinate & "
                            "Enter & Y coordinate & Enter!" << endl;

                    cin >> x >> y;

                    cout << endl;

                    chosenCard = playerList[k].yourHand[c];

                    chosenCard->setOrientation((Orientation)orientation);

                    nbdraws[k] = gameBoard.addAt(chosenCard, y, x);
                } catch (...) {
                    cout << "Uh oh, invalid play. Try again." << endl;
                    continue;
                }
                break;
            }

            playerList[k].yourHand -= chosenCard;

            // If it's an action card:
            if (shared_ptr<ActionCard> actionCard
                = dynamic_pointer_cast<ActionCard>(chosenCard)) {

                actionCard->setGameInfo({k, i});
                QueryResult queryResult = actionCard->query();
                actionCard->perform(gameBoard, playerList, queryResult);
            }

            for (int m = 0; m != i; m++) {

                string name = playerList[m].getName();

                if (gameBoard.win(name))
                    playerHasWon = true;
            }
        }
    }

    return 0;
}
