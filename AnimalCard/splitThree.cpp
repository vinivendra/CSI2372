
#include <iostream>

#include "splitThree.h"


SplitThree::SplitThree(Animal _animals[2][2])
    : row(EvenOdd::EVEN), orientation(Orientation::UP) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->animals[i][j] = _animals[i][j];
        }
    }
}

void SplitThree::print(ostream& o) const {
    switch (row) {
        case EvenOdd::EVEN: {
            o << charForAnimal(this->animals[0][0]);
            o << charForAnimal(this->animals[0][1]);
            break;
        }
        case EvenOdd::ODD: {
            o << charForAnimal(this->animals[1][0]);
            o << charForAnimal(this->animals[1][1]);
            break;
        }
        default: { break; }
    }
}

void SplitThree::setOrientation(Orientation newValue) {
    if (newValue != orientation) {
        orientation = newValue;
        Animal newAnimals[2][2];
        newAnimals[0][0] = animals[1][1];
        newAnimals[0][1] = animals[1][0];
        newAnimals[1][0] = animals[0][1];
        newAnimals[1][1] = animals[0][0];
        for (int i = 0; i != 2; i++) {
            for (int j = 0; j != 2; j++) {
                animals[i][j] = newAnimals[i][j];
            }
        }
    }
}

void SplitThree::setRow(EvenOdd newValue) {
    if (row != EvenOdd::DEFAULT) {
        row = newValue;
    }
}

EvenOdd SplitThree::getRow() {
    return row;
}

void SplitThree::printRow(EvenOdd row) {
    switch (row) {
    case EvenOdd::EVEN: {
        cout << charForAnimal(this->animals[0][0]);
        cout << charForAnimal(this->animals[0][1]);
        break;
    }
    case EvenOdd::ODD: {
        cout << charForAnimal(this->animals[1][0]);
        cout << charForAnimal(this->animals[1][1]);
        break;
    }
    default: {
        printRow(this->row);
        break;
    }
    }
}

Animal SplitThree::getAnimal(int i) {
    return animals[i / 2][i % 2];
}
