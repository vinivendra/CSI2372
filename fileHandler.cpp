

#include "fileHandler.h"
#include <fstream>


static string filename = "gameSave.txt";


void writeTableToFile(ostream& o, Table *table);
void writePlayersToFile(ostream& o, Player *playerList, int numberOfPlayers);
void writeDeckToFile(ostream& o, Deck<AnimalCard> *deck);


void writeToFile(Table *table,
                 Deck<AnimalCard> *deck,
                 Player *playerList,
                 int numberOfPlayers) {
    ofstream file;
    file.open(filename);

    writePlayersToFile(file, playerList, numberOfPlayers);
    writeDeckToFile(file, deck);
    writeTableToFile(file, table);

    file.close();
}

void writeTableToFile(ostream& o, Table *table) {
    table->writeToFile(o);
}

void writePlayersToFile(ostream& o, Player *playerList, int numberOfPlayers) {
    o << numberOfPlayers << endl;
    for (int i = 0; i < numberOfPlayers; i++) {
        playerList[i].writeToFile(o);
    }
}

void writeDeckToFile(ostream& o, Deck<AnimalCard> *deck) {
    o << deck->size() << endl;

    for (int i = 0; i < deck->size(); i++) {
        deck->at(i)->writeToFile(o);
        o << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////

void readToFile(Table *table,
                Player **playerList,
                int &numberOfPlayers) {
    ifstream file;
    file.open(filename);

    file >> numberOfPlayers;

    Player *players = new Player[numberOfPlayers];
    *playerList = players;

    for (int i = 0; i < numberOfPlayers; i++) {
        string name;
        string secretAnimal;
        int numberOfCards;

        getline(file, name);
        getline(file, name);
        file >> secretAnimal;
        file >> numberOfCards;

        players[i].setName(name);
        players[i].swapSecretAnimal(secretAnimal);

        for (int j = 0; j < numberOfCards; j++) {
            string cardString;
            file >> cardString;

            shared_ptr<AnimalCard> card =
                AnimalCardFactory::createCard(cardString);

            players[i].yourHand += card;
        }
    }

    int numberOfDeckCards;
    file >> numberOfDeckCards;

    for (int i = 0; i < numberOfDeckCards; i++) {
        string cardString;
        file >> cardString;

        AnimalCardFactory::getFactory()->addCardToDeck(cardString);
    }

    int numberOfStackCards;
    file >> numberOfStackCards;

    for (int i = 0; i < numberOfStackCards; i++) {
        string cardString;
        file >> cardString;

        shared_ptr<AnimalCard> card =
            AnimalCardFactory::createCard(cardString);

        if (shared_ptr<NoSplit> noSplit =
                dynamic_pointer_cast<NoSplit>(card)) {
            *table += noSplit;
        }
    }

    while (true) {
        int x, y;
        file >> x;
        file >> y;

        if (file.eof())
            break;

        string cardString;
        file >> cardString;

        shared_ptr<AnimalCard> card =
            AnimalCardFactory::createCard(cardString);

        table->insert(card, x, y);
    }

    file.close();
}
