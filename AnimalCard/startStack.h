
#ifndef startStack_h
#define startStack_h

#include "animalCard.h"
#include "actionCard.h"
#include "startCard.h"

#include <deque>


using namespace std;


class StartStack : AnimalCard {
    deque<shared_ptr<ActionCard>> stack;
    EvenOdd row;
    Orientation orientation;

public:
    void print(ostream& o) const;

    void setOrientation(Orientation);
    void setRow(EvenOdd);
    EvenOdd getRow();
    void printRow(EvenOdd);
    Animal getAnimal(int);

    StartStack& operator+=(std::shared_ptr<ActionCard>);
    StartStack& operator-=(std::shared_ptr<ActionCard>);
    std::shared_ptr<StartCard> getStartCard();
};

#endif
