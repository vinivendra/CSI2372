#include "AnimalCardFactory.h"

#include "../../AnimalCard/ActionCard/bearAction.h"
#include "../../AnimalCard/ActionCard/deerAction.h"
#include "../../AnimalCard/ActionCard/hareAction.h"
#include "../../AnimalCard/ActionCard/mooseAction.h"
#include "../../AnimalCard/ActionCard/wolfAction.h"

#include "../../AnimalCard/splitFour.h"
#include "../../AnimalCard/splitThree.h"
#include "../../AnimalCard/splitTwo.h"

#include <algorithm>
#include <random>


void addCard(Deck<AnimalCard> &deck, shared_ptr<AnimalCard> newCard) {
    deck.push_back(newCard);
}

void addCard(Deck<AnimalCard> &deck, AnimalCard *newCard) {
    addCard(deck, (shared_ptr<AnimalCard>)((AnimalCard *)newCard));
}

AnimalCardFactory::AnimalCardFactory() {
}

void AnimalCardFactory::randomizeDeck() {
    addCard(deck, new BearAction());
    addCard(deck, new DeerAction());
    addCard(deck, new HareAction());
    addCard(deck, new MooseAction());
    addCard(deck, new WolfAction());

    for (int i = 1; i < 6; i++) {

        for (int j = i + 1; j < 6; j++) {
            Animal twoSplit[2][2]{{(Animal)i, (Animal)i},
                {(Animal)j, (Animal)j}};
            addCard(deck, new SplitTwo(twoSplit));

            Animal twoSplitBis[2][2]{{(Animal)i, (Animal)j},
                {(Animal)i, (Animal)j}};
            addCard(deck, new SplitTwo(twoSplitBis));

            for (int k = j + 1; k < 6; k++) {
                Animal threeSplit[2][2]{(Animal)i,
                    (Animal)j,
                    (Animal)i,
                    (Animal)k};
                addCard(deck, new SplitThree(threeSplit));

                Animal threeSplitBis[2][2]{(Animal)i,
                    (Animal)i,
                    (Animal)k,
                    (Animal)j};
                addCard(deck, new SplitThree(threeSplitBis));

                for (int m = k + 1; m < 6; m++) {
                    Animal fourSplit[2][2]{(Animal)i,
                        (Animal)j,
                        (Animal)k,
                        (Animal)m};
                    addCard(deck, new SplitThree(fourSplit));

                    Animal fourSplitBis[2][2]{(Animal)m,
                        (Animal)i,
                        (Animal)j,
                        (Animal)k};
                    addCard(deck, new SplitThree(fourSplitBis));

                    Animal fourSplitBisBis[2][2]{(Animal)k,
                        (Animal)m,
                        (Animal)i,
                        (Animal)j};
                    addCard(deck, new SplitThree(fourSplitBisBis));
                }
            }
        }
    }

    // Shuffling the set of cards
    auto engine = default_random_engine{};
    shuffle(begin(deck), end(deck), engine);
    // deckFactory = this;
}

AnimalCardFactory *AnimalCardFactory::getFactory() {
    static AnimalCardFactory deckFactory;
    return &deckFactory;
}

Deck<AnimalCard> &AnimalCardFactory::getDeck() {
    return deck;
}

AnimalCardFactory *AnimalCardFactory::readFromFile(istream &i) {
    return getFactory();
}

shared_ptr<AnimalCard> AnimalCardFactory::createCard(string animals) {
    AnimalCard *newCard;

    if (animals.at(0) == animals.at(1) &&
        animals.at(0) == animals.at(2) &&
        animals.at(0) == animals.at(3)) {

        if (animals.at(0) == charForAnimal(Animal::WOLF)) {
            newCard = new WolfAction();
        }
        else if (animals.at(0) == charForAnimal(Animal::BEAR)) {
            newCard = new BearAction();
        }
        else if (animals.at(0) == charForAnimal(Animal::DEER)) {
            newCard = new DeerAction();
        }
        else if (animals.at(0) == charForAnimal(Animal::HARE)) {
            newCard = new HareAction();
        }
        else if (animals.at(0) == charForAnimal(Animal::MOOSE)) {
            newCard = new MooseAction();
        }
        else if (animals.at(0) == charForAnimal(Animal::ALL)) {
            newCard = new StartCard();
        }
    }

    else if ((animals.at(0) == animals.at(1) &&
              animals.at(2) == animals.at(3)) ||
             (animals.at(0) == animals.at(2) &&
              animals.at(1) == animals.at(3))) {
        Animal array[2][2]{{animalForChar(animals.at(0)),
                            animalForChar(animals.at(1))},
                           {animalForChar(animals.at(2)),
                            animalForChar(animals.at(3))}};
        newCard = new SplitTwo(array);
    }

    else if (animals.at(0) == animals.at(1) ||
             animals.at(2) == animals.at(3) ||
             animals.at(0) == animals.at(2) ||
             animals.at(1) == animals.at(3)) {
        Animal array[2][2]{{animalForChar(animals.at(0)),
                            animalForChar(animals.at(1))},
                           {animalForChar(animals.at(2)),
                            animalForChar(animals.at(3))}};
        newCard = new SplitThree(array);
    }

    else {
        Animal array[2][2]{{animalForChar(animals.at(0)),
                            animalForChar(animals.at(1))},
                           {animalForChar(animals.at(2)),
                            animalForChar(animals.at(3))}};
        newCard = new SplitFour(array);
    }

    return (shared_ptr<AnimalCard>)((AnimalCard *)newCard);
}

void AnimalCardFactory::addCardToDeck(string animals) {
    shared_ptr<AnimalCard> card = createCard(animals);
    addCard(deck, card);
}

