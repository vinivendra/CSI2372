
#ifndef fileHandler_h
#define fileHandler_h

#include <string>

#include "Container/Table/table.h"
#include "Container/AnimalCardFactory/AnimalCardFactory.h"
#include "Container/Player/player.h"


using namespace std;


void writeToFile(Table *table,
                 Deck<AnimalCard> *deck,
                 Player *playerList,
                 int numberOfPlayers);

void readToFile(Table *table,
                Player **playerList,
                int &numberOfPlayers);

#endif
