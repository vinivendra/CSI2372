

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
        file >> players[i];
    }

    file >> *AnimalCardFactory::getFactory();

    file >> *table;

    file.close();
}
