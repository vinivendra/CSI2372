

#include "actionCard.h"


ActionCard::ActionCard(Animal animal) : StartCard(animal) {
}

char uppercaseCharForAnimal(Animal animal) {
    char lowercase = charForAnimal(animal);
    char uppercase = lowercase - 'a' + 'A';
    return uppercase;
}

void ActionCard::printRow(EvenOdd row) {
    std::cout << uppercaseCharForAnimal(animal);
    std::cout << uppercaseCharForAnimal(animal);
}

void ActionCard::setCurrentPlayer(int newValue) {
    currentPlayer = newValue;
}
