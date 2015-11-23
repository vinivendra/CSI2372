

#include <iostream>

#include "splitFour.h"


using namespace std;


SplitFour::SplitFour(Animal animals[2][2])
    : row(EvenOdd::EVEN), orientation(Orientation::UP) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->animals[i][j] = animals[i][j];
        }
    }
}

void SplitFour::print(ostream& o) const {
}

void SplitFour::setOrientation(Orientation newValue) {
    orientation = orientation;
}

void SplitFour::setRow(EvenOdd newValue) {
    row = newValue;
}

EvenOdd SplitFour::getRow() {
    return row;
}

void SplitFour::printRow(EvenOdd row) {
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

Animal SplitFour::getAnimal(int i) {
	return animals[i / 2][i % 2];
}
