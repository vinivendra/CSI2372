// TODO: Make sure everything that can be const is const
// TODO: Make sure everything that can be private or protected is too
// TODO: Write to file and read from file

#include <iostream>

#include "AnimalCard/animalCard.h"
#include "AnimalCard/ActionCard/actionCard.h"
#include "AnimalCard/startStack.h"
#include "Container/Table/table.h"
#include "Container/AnimalCardFactory/AnimalCardFactory.h"
#include "Container/Player/player.h"
#include "Container/Deck/deck.h"
#include "fileHandler.h"

#include <vector>

using namespace std;


int main(int argc, const char *argv[]) {

    // Game loop

    AnimalCardFactory *factory = AnimalCardFactory::getFactory();
    Table *gameBoard = new Table();
    Player *playerList = nullptr;

    int i = 0;

    bool shouldReadFromFile = false;
    cout << "Would you like to load the game from a file? [0/1] ";
    cin >> shouldReadFromFile;

    if (shouldReadFromFile) {
        readToFile(gameBoard, &playerList, i);

        for (int k = 0; k < i; k++) {
            playerList[k].yourHand += factory->getDeck().draw();
        }
    } else {
        cout << "How many players are playing? (2-5 players) ";

        while (i == 0) {
            cin >> i;
        }
        cout << endl;

        factory->randomizeDeck();

        playerList = new Player[i];

        string name;

        for (int j = 0; j != i; j++) {
            playerList[j].setupAndDrawCards();

            cout << "Name of player " << j + 1 << ": ";
            cin >> name;
            playerList[j].setName(name);
            cout << endl;
        }

        *gameBoard += shared_ptr<StartCard>(new StartCard());
    }

    int nbdraws[5] = {0, 0, 0, 0, 0};

    bool playerHasWon = false;

    while (!playerHasWon) {
        // If pause save game to file and exit
        bool shouldPause = false;
        cout << "Would you like to pause, save and exit? [0/1] " << endl;
        cin >> shouldPause;

        if (shouldPause) {
            cout << "Saving information to gameSave.txt..." << endl;
            writeToFile(gameBoard, &factory->getDeck(), playerList, i);
            cout << "Game saved sucessfully. Goodbye!" << endl;
            return 0;
        }

        for (int k = 0; k != i; k++) {

            cout << "Table: " << endl;
            gameBoard->print();

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

                    // If we're setting a card on the startStack
                    if (x == 52 && y == 52) {
                        if (shared_ptr<ActionCard> actionCard
                            = dynamic_pointer_cast<ActionCard>(chosenCard)) {

                            cout << "Would you like to place the card at the "
                                    "top of the stack or at the bottom? [1/0] ";

                            bool choiceIsTop;
                            cin >> choiceIsTop;

                            if (choiceIsTop) {
                                *gameBoard += actionCard;
                            } else {
                                *gameBoard -= actionCard;

                                actionCard->setGameInfo({k, i});
                                QueryResult queryResult = actionCard->query();
                                actionCard->perform(*gameBoard,
                                                    playerList,
                                                    queryResult);
                            }


                        } else {
                            cout << "Only action cards may be placed on the "
                                    "stack." << endl;
                            throw IllegalPlacement(x, y);
                        }
                    } else {
                        chosenCard->setOrientation((Orientation)orientation);

                        nbdraws[k] = gameBoard->addAt(chosenCard, y, x);
                    }
                } catch (...) {
                    cout << "Uh oh, invalid play. Try again." << endl;
                    continue;
                }
                break;
            }

            playerList[k].yourHand -= chosenCard;

            for (int m = 0; m != i; m++) {

                string name = playerList[m].getName();

                if (gameBoard->win(name))
                    playerHasWon = true;
            }
        }
    }

    return 0;
}
