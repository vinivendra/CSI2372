#include <iostream>
#include "splitTwo.h"


SplitTwo::SplitTwo(Animal _animals[2])
	: row(EvenOdd::EVEN), orientation(Orientation::UP) {
	for (int i = 0; i < 2; i++) {
		this->animals[i] = _animals[i];
	}
}

void SplitTwo::print(ostream& o) const {
}

void SplitTwo::setOrientation(Orientation newValue) {
	if (newValue != orientation) {
		orientation = newValue;
		Animal tempAnimals(animals[0]);
		animals[0] = animals[1];
		animals[1] = tempAnimals;
	}
}

void SplitTwo::setRow(EvenOdd newValue) {
	row = newValue;
}

EvenOdd SplitTwo::getRow() {
	return row;
}

void SplitTwo::printRow(EvenOdd row) {
	cout << charForAnimal(animals[0]);
	cout << charForAnimal(animals[1]);
}

Animal SplitTwo::getAnimal(int i) {
	return animals[i % 2];
}