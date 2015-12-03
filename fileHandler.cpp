

#include "fileHandler.h"
#include <fstream>


void writeTableToFile(ostream& o, Table *table);
void writePlayersToFile(ostream& o, Player *playerList, int numberOfPlayers);
void writeDeckToFile(ostream& o, Deck<AnimalCard> *deck);


void writeToFile(string filename,
                 Table *table,
                 Deck<AnimalCard> *deck,
                 Player *playerList,
                 int numberOfPlayers) {
    // Write basic info: whose turn is it, player names, etc.

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


