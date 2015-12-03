
#include "fileHandler.h"

void writeTableToFile(ostream& o, Table *table);
void writePlayersToFile(ostream& o, Player *playerList, int numberOfPlayers);
void writeDeckToFile(ostream& o, Deck<AnimalCard> *deck);


void writeToFile(string filename,
                 Table *table,
                 Deck<AnimalCard> *deck,
                 Player *playerList,
                 int numberOfPlayers) {
    // Write basic info: whose turn is it, player names, etc.

    ostream *o = &cout;

    writePlayersToFile(*o, playerList, numberOfPlayers);
    writeDeckToFile(*o, deck);
    writeTableToFile(*o, table);
}

void writeTableToFile(ostream& o, Table *table) {
    table->writeToFile(o);
}

void writePlayersToFile(ostream& o, Player *playerList, int numberOfPlayers) {
    cout << numberOfPlayers << endl;
    for (int i = 0; i < numberOfPlayers; i++) {
        playerList[i].writeToFile(o);
    }
}

void writeDeckToFile(ostream& o, Deck<AnimalCard> *deck) {
    // Write the Deck's contents
}


