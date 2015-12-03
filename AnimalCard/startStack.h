
#ifndef startStack_h
#define startStack_h

#include "animalCard.h"
#include "ActionCard/actionCard.h"
#include "startCard.h"

#include <deque>


using namespace std;


class StartStack : public AnimalCard {
    deque<shared_ptr<NoSplit>> stack;
    EvenOdd row;
    Orientation orientation;

public:
    void print(ostream& o) const;

    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow();
    virtual void printRow(EvenOdd);
    virtual Animal getAnimal(int);

    StartStack();

    StartStack& operator+=(std::shared_ptr<ActionCard>);
    StartStack& operator-=(shared_ptr<ActionCard>);
    shared_ptr<StartCard> getStartCard();
};

#endif
