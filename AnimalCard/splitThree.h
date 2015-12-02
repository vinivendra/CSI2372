
#ifndef splitThree_h
#define splitThree_h


#include "animalCard.h"


class SplitThree : public AnimalCard {
    EvenOdd row;
    Orientation orientation;
    Animal animals[2][2];

protected:
    virtual void print(ostream& o) const;

public:
    SplitThree(Animal[2][2]);

    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow();
    virtual void printRow(EvenOdd);
    virtual Animal getAnimal(int);
};

#endif
