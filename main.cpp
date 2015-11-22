

#include <iostream>

#include "animalCard.h"
#include "splitFour.h"


using namespace std;


int main(int argc, const char *argv[]) {

    Animal animals[2][2]
        = {{Animal::BEAR, Animal::DEER}, {Animal::WOLF, Animal::HARE}};
    SplitFour card = SplitFour(animals);

    card.printRow(EvenOdd::EVEN);
    cout << endl;
    card.printRow(EvenOdd::ODD);

    cout << endl << "Hello, World!\n" << endl;

    return 0;
}
