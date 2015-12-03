#ifndef deck_h
#define deck_h

#include <vector>
#include <memory>
#include <iostream>


using namespace std;


template <class T> class Deck : public vector<shared_ptr<T>> {
public:
    shared_ptr<T> draw() {
        shared_ptr<T> result = this->back();
        this->pop_back();
        return result;
    };
};


#endif
