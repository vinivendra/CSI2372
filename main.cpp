

#include <iostream>

#include "AnimalCard/animalCard.h"
#include "AnimalCard/splitFour.h"
#include "Table/table.h"


using namespace std;


int main(int argc, const char *argv[]) {

    Animal animals[2][2]
        = {{Animal::BEAR, Animal::DEER}, {Animal::WOLF, Animal::HARE}};
    SplitFour card = SplitFour(animals);

    card.printRow(EvenOdd::EVEN);
    cout << endl;
    card.printRow(EvenOdd::ODD);

    cout << endl << "Hello, World!\n" << endl;

	Table* testTable = new Table();

	std::shared_ptr<AnimalCard> cardToAdd((AnimalCard*)new SplitFour(animals));

	testTable->addAt(cardToAdd, 52, 52);

	testTable->print();

	delete testTable;

    return 0;
}
