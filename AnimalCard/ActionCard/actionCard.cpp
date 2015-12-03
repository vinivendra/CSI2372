

#include "actionCard.h"


ActionCard::ActionCard(Animal animal) : StartCard(animal) {
}

char uppercaseCharForAnimal(Animal animal) {
    char lowercase = charForAnimal(animal);
    char uppercase = lowercase - 'a' + 'A';
    return uppercase;
}

void ActionCard::printRow(EvenOdd row) {
    cout << uppercaseCharForAnimal(animal);
    cout << uppercaseCharForAnimal(animal);
}

void ActionCard::setGameInfo(GameInfo gameInfo) {
    this->gameInfo = gameInfo;
}