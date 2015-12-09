
#ifndef startStack_h
#define startStack_h

#include "animalCard.h"
#include "startCard.h"

#include <deque>
#include <memory>


using namespace std;


class StartStack : public AnimalCard {
    deque<shared_ptr<NoSplit>> stack;
    EvenOdd row;
    Orientation orientation;

public:
    StartStack();

    void print(ostream& o) const;

    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow() const;
    virtual void printRow(EvenOdd) const;
    virtual Animal getAnimal(int) const;

    virtual void writeToFile(ostream& o) const;

    StartStack& operator+=(shared_ptr<NoSplit>);
    StartStack& operator-=(shared_ptr<NoSplit>);
    shared_ptr<StartCard> getStartCard();
};

#endif
