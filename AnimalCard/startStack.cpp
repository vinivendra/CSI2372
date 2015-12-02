

#include "startStack.h"


using namespace std;


void StartStack::print(ostream& o) const {
    
}

void StartStack::setOrientation(Orientation orientation) {
    shared_ptr<ActionCard>card = stack.front();
    stack.front()->setOrientation(orientation);
}

void StartStack::setRow(EvenOdd row) {
    stack.front()->setRow(row);
}

EvenOdd StartStack::getRow() {
    return stack.front()->getRow();
}

void StartStack::printRow(EvenOdd row) {
    stack.front()->printRow(row);
}

Animal StartStack::getAnimal(int index) {
    return stack.front()->getAnimal(index);
}

StartStack& StartStack::operator+=(shared_ptr<ActionCard> newValue) {
    stack.push_front(newValue);
    return *this;
}

StartStack& StartStack::operator-=(shared_ptr<ActionCard> newValue) {
    stack.push_back(newValue);
    return *this;
}

shared_ptr<StartCard> StartStack::getStartCard() {
    return shared_ptr<StartCard>();
}
