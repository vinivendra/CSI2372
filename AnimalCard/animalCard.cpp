

#include "animalCard.h"


char charForAnimal(Animal animal) {
    switch (animal) {
    case Animal::BEAR:
        return 'b';
        break;
    case Animal::DEER:
        return 'd';
        break;
    case Animal::HARE:
        return 'h';
        break;
    case Animal::MOOSE:
        return 'm';
        break;
    case Animal::WOLF:
        return 'w';
        break;
    default:
        return 'x';
        break;
    }
}

AnimalCard::AnimalCard() :row(EvenOdd::EVEN), orientation(Orientation::UP) {};

Animal AnimalCard::getAnimal(int i) {
	return animals[i / 2][i % 2];
}
