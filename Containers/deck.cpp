

#include "deck.h"

using namespace std;


template <class T>
std::shared_ptr<T> Deck<T>::draw() {

    std::shared_ptr<T> result = this->back();
    this->pop_back();

    return result;
}
