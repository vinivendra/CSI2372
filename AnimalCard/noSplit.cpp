#include <iostream>

#include "noSplit.h"

NoSplit::NoSplit(Animal _animal):row(EvenOdd::EVEN), orientation(Orientation::UP){
	animal = _animal;
}

void NoSplit::print(ostream& o) const {
}

void NoSplit::setOrientation(Orientation _orientation) {
	orientation = _orientation;
	//Do nothing
}

void NoSplit::setRow(EvenOdd newRow) {
	row = newRow;
}

EvenOdd NoSplit::getRow() {
	return row;
}

void NoSplit::printRow(EvenOdd row) {
	std::cout << charForAnimal(animal);
	std::cout << charForAnimal(animal);
}

Animal NoSplit::getAnimal(int) {
	return animal;
}