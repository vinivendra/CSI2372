

#include "deck.h"

using namespace std;


template <class T>
shared_ptr<T> Deck<T>::draw() {

    shared_ptr<T> result = this->back();
    this->pop_back();

    return result;
}
