#include "AnimalCardFactory.h"
#include "../../AnimalCard/noSplit.h"
#include "../../AnimalCard/splitFour.h"
#include "../../AnimalCard/splitThree.h"
#include "../../AnimalCard/splitTwo.h"

#include <algorithm>
#include <random>

// AnimalCardFactory* AnimalCardFactory::deckFactory = nullptr;

AnimalCardFactory::AnimalCardFactory() {

    // We add the 50 animal cards to the deck
    for (int i = 1; i < 6; i++) {
        deck.push_back(
            (std::shared_ptr<AnimalCard>)((AnimalCard*)new NoSplit((Animal)i)));
        for (int j = i + 1; j < 6; j++) {
            Animal twoSplit[2]{(Animal)i, (Animal)j};
            deck.push_back((std::shared_ptr<AnimalCard>)((
                AnimalCard*)new SplitTwo(twoSplit)));
            for (int k = j + 1; k < 6; k++) {
                Animal threeSplit[2][2]{(Animal)i,
                                        (Animal)j,
                                        (Animal)i,
                                        (Animal)k};
                deck.push_back((std::shared_ptr<AnimalCard>)((
                    AnimalCard*)new SplitThree(threeSplit)));
                Animal threeSplitBis[2][2]{(Animal)i,
                                           (Animal)i,
                                           (Animal)k,
                                           (Animal)j};
                deck.push_back((std::shared_ptr<AnimalCard>)((
                    AnimalCard*)new SplitThree(threeSplitBis)));
                for (int m = k + 1; m < 6; m++) {
                    Animal fourSplit[2][2]{(Animal)i,
                                           (Animal)j,
                                           (Animal)k,
                                           (Animal)m};
                    deck.push_back((std::shared_ptr<AnimalCard>)((
                        AnimalCard*)new SplitThree(fourSplit)));
                    Animal fourSplitBis[2][2]{(Animal)m,
                                              (Animal)i,
                                              (Animal)j,
                                              (Animal)k};
                    deck.push_back((std::shared_ptr<AnimalCard>)((
                        AnimalCard*)new SplitThree(fourSplitBis)));
                    Animal fourSplitBisBis[2][2]{(Animal)k,
                                                 (Animal)m,
                                                 (Animal)i,
                                                 (Animal)j};
                    deck.push_back((std::shared_ptr<AnimalCard>)((
                        AnimalCard*)new SplitThree(fourSplitBisBis)));
                }
            }
        }
    }
    // Shuffling the set of cards
    auto engine = std::default_random_engine{};
    std::shuffle(std::begin(deck), std::end(deck), engine);
    // deckFactory = this;
}

AnimalCardFactory* AnimalCardFactory::getFactory() {
    static AnimalCardFactory deckFactory;
    return &deckFactory;
}

Deck<AnimalCard>& AnimalCardFactory::getDeck() {
    return deck;
}