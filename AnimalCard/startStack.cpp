

#include "startStack.h"


using namespace std;

StartStack::StartStack() {
    stack.push_back(shared_ptr<NoSplit>(new StartCard()));
}

void StartStack::print(ostream& o) const {
    
}

void StartStack::setOrientation(Orientation orientation) {
    shared_ptr<NoSplit>card = stack.front();
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
    Animal animal = stack.front()->getAnimal(index);
    return animal;
}

StartStack& StartStack::operator+=(shared_ptr<NoSplit> newValue) {
    stack.push_front(newValue);
    return *this;
}

StartStack& StartStack::operator-=(shared_ptr<NoSplit> newValue) {
    stack.push_back(newValue);
    return *this;
}

shared_ptr<StartCard> StartStack::getStartCard() {
    return shared_ptr<StartCard>();
}
