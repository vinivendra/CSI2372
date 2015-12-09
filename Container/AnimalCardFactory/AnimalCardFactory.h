#ifndef animalCardFactory_hpp
#define animalCardFactory_hpp

#include "../Deck/deck.h"
#include "../../AnimalCard/animalCard.h"

class AnimalCardFactory {
    Deck<AnimalCard> deck;
    static AnimalCardFactory* deckFactory;

    AnimalCardFactory();
    
public:
    static AnimalCardFactory* getFactory();
    static AnimalCardFactory* readFromFile(istream &i);

    void randomizeDeck();

    Deck<AnimalCard>& getDeck();

    static shared_ptr<AnimalCard> createCard(string animals);
    void addCardToDeck(string animals);
};

#endif