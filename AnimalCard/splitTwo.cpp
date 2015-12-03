
#include <iostream>

#include "splitTwo.h"


SplitTwo::SplitTwo(Animal animals[2][2])
    : row(EvenOdd::EVEN), orientation(Orientation::UP) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->animals[i][j] = animals[i][j];
        }
    }
}

void SplitTwo::print(ostream& o) const {
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

void SplitTwo::setOrientation(Orientation newValue) {
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

void SplitTwo::setRow(EvenOdd newValue) {
    if (row != EvenOdd::DEFAULT) {
        row = newValue;
    }
}

EvenOdd SplitTwo::getRow() const {
    return row;
}

void SplitTwo::printRow(EvenOdd row) const {
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

Animal SplitTwo::getAnimal(int i) const {
    return animals[i / 2][i % 2];
}
