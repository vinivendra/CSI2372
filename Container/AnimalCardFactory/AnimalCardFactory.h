#ifndef animalCardFactory_hpp
#define animalCardFactory_hpp

#include "../Deck/deck.h"
#include "../../AnimalCard/animalCard.h"

class AnimalCardFactory {
    Deck<AnimalCard> deck;
    static AnimalCardFactory* deckFactory;

    AnimalCardFactory();

    void addCardToDeck(string animals);
    
public:
    static AnimalCardFactory* getFactory();
    static AnimalCardFactory* readFromFile(istream &i);

    void randomizeDeck();

    Deck<AnimalCard>& getDeck();

    static shared_ptr<AnimalCard> createCard(string animals);

    inline friend istream& operator>>(istream& file,
                                      AnimalCardFactory& factory) {
        int numberOfDeckCards;
        file >> numberOfDeckCards;

        for (int i = 0; i < numberOfDeckCards; i++) {
            string cardString;
            file >> cardString;

            factory.addCardToDeck(cardString);
        }

        return file;
    }
};

#endif