#include "player.h"
#include "../AnimalCardFactory/AnimalCardFactory.h"

int Player::nextAnimal = 0;

void Player::setName(std::string _namePlayer){
	playerName = _namePlayer;
}

std::string Player::getName() {
	return playerName;
}

Player::Player() {
	nextAnimal++;
	secretAnimal = charForAnimal((Animal)nextAnimal);
	for (int i = 0; i != 3;i++)
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

void Player::print(std::ostream& o) const {
	o << "Secret animal: " << secretAnimal << std::endl;
	o << yourHand;
}