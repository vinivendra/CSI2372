#include "Hand.h"
#include <algorithm>

Hand& Hand::operator+=(std::shared_ptr<AnimalCard> newCard) {
	this->hand.push_back(newCard);
	return (*this);
}

Hand& Hand::operator-=(std::shared_ptr<AnimalCard> oldCard) {
	std::vector<std::shared_ptr<AnimalCard>>::iterator position = std::find(hand.begin(), hand.end(), oldCard);
	if (position != hand.end())
		hand.erase(position);
	return (*this);
}

std::shared_ptr<AnimalCard> Hand::operator[](int i) {
	return hand[i];
}

int Hand::noCards() {
	return (int)hand.size();
}

void Hand::print(ostream& o) const{
	for (int i = 0; i != hand.size(); i++) {
		o << i << "  ";
	}
	o << std::endl;
	for (int i = 0; i != hand.size(); i++) {
		hand[i]->printRow((EvenOdd)0);
		o << " ";
	}
	o << std::endl;
	for (int i = 0; i != hand.size(); i++) {
		hand[i]->printRow((EvenOdd)1);
		o << " ";
	}
}