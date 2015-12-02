
#include <iostream>

#include "noSplit.h"


NoSplit::NoSplit(Animal _animal)
    : row(EvenOdd::EVEN) {
    animal = _animal;
}

void NoSplit::print(ostream& o) const {
    o << charForAnimal(animal) << charForAnimal(animal);
}

void NoSplit::setOrientation(Orientation _orientation) {
}

void NoSplit::setRow(EvenOdd newValue) {
    if (row != EvenOdd::DEFAULT) {
        row = newValue;
    }
}

EvenOdd NoSplit::getRow() {
    return row;
}

void NoSplit::printRow(EvenOdd row) {
    std::cout << charForAnimal(animal) << charForAnimal(animal);
}

Animal NoSplit::getAnimal(int) {
    return animal;
}
