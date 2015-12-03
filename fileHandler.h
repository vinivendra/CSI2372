
#ifndef fileHandler_h
#define fileHandler_h

#include <string>

#include "Container/Table/table.h"
#include "Container/Deck/deck.h"
#include "Container/Player/player.h"


using namespace std;


void writeToFile(string filename,
                 Table *table,
                 Deck<AnimalCard> *deck,
                 Player *playerList,
                 int numberOfPlayers);

#endif
