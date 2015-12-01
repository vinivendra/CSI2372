

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
	case Animal::ALL:
		return '*';
		break;
    default:
        return 'x';
        break;
    }
}
