

#include <iostream>

#include "AnimalCard/animalCard.h"
#include "AnimalCard/splitFour.h"
#include "Containers/table.h"
//#include "Containers/deck.h"

#include <vector>

using namespace std;


template <class T> class Deck : public std::vector<T> {
public:
    std::shared_ptr<T> draw();
};

template <class T> std::shared_ptr<T> Deck<T>::draw() {

    std::shared_ptr<T> result(new T(this->back()));
    this->pop_back();

    return result;
}


int main(int argc, const char *argv[]) {

    Animal animals[2][2]
        = {{Animal::BEAR, Animal::DEER}, {Animal::WOLF, Animal::HARE}};
    SplitFour card = SplitFour(animals);

    card.printRow(EvenOdd::EVEN);
    cout << endl;
    card.printRow(EvenOdd::ODD);


    //
    Table *testTable = new Table();

    std::shared_ptr<AnimalCard> cardToAdd((AnimalCard *)new SplitFour(animals));

    testTable->addAt(cardToAdd, 52, 52);

    testTable->print();


    //
    SplitFour deckCard = SplitFour(animals);
    Deck<AnimalCard> deck = Deck<AnimalCard>();
    deck.push_back(deckCard);
    shared_ptr<AnimalCard> resultCard = deck.draw();

    resultCard->printRow(EvenOdd::EVEN);
    cout << endl;
    resultCard->printRow(EvenOdd::EVEN);
    cout << endl;

    delete testTable;

    return 0;
}
