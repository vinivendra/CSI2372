
#include "player.h"
#include "../AnimalCardFactory/AnimalCardFactory.h"


using namespace std;


int Player::nextAnimal = 0;

void Player::setName(std::string _namePlayer) {
    playerName = _namePlayer;
}

std::string Player::getName() {
    return playerName;
}

Player::Player() {
    nextAnimal++;
    secretAnimal = charForAnimal((Animal)nextAnimal);
    for (int i = 0; i != 3; i++)
        yourHand += AnimalCardFactory::getFactory()->getDeck().draw();
}

std::string Player::swapSecretAnimal(std::string& newAnimal) {
    std::string oldAnimal = this->getSecretAnimal();
    this->secretAnimal = newAnimal;
    return oldAnimal;
}

std::string Player::getSecretAnimal() {
    return this->secretAnimal;
}

void Player::writeToFile(ostream& o) {
    o << playerName << endl;
    o << secretAnimal << endl;
    yourHand.writeToFile(o);
}

void Player::print(ostream& o) const {
    cout << "Secret animal: " << secretAnimal << endl;
    cout << yourHand;
}
