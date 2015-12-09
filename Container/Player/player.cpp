
#include "player.h"
#include "../AnimalCardFactory/AnimalCardFactory.h"


using namespace std;


int Player::nextAnimal = 0;

void Player::setName(string _namePlayer) {
    playerName = _namePlayer;
}

string Player::getName() {
    return playerName;
}

Player::Player() {

}

void Player::setupAndDrawCards() {
    nextAnimal++;
    secretAnimal = charForAnimal((Animal)nextAnimal);
    for (int i = 0; i != 3; i++)
        yourHand += AnimalCardFactory::getFactory()->getDeck().draw();
}

string Player::swapSecretAnimal(string& newAnimal) {
    string oldAnimal = this->getSecretAnimal();
    this->secretAnimal = newAnimal;
    return oldAnimal;
}

string Player::getSecretAnimal() {
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
