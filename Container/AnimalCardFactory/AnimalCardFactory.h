#ifndef animalCardFactory_hpp
#define animalCardFactory_hpp

#include "../Deck/deck.h"
#include "../../AnimalCard/animalCard.h"

class AnimalCardFactory {
	Deck<AnimalCard> deck;
	//static AnimalCardFactory* deckFactory;
public:
	AnimalCardFactory();
	static AnimalCardFactory* getFactory();
	Deck<AnimalCard>& getDeck();
};

#endif