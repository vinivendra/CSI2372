
#ifndef SplitFour_h
#define SplitFour_h


#include "animalCard.h"


class SplitFour : public AnimalCard {
    EvenOdd row;
    Orientation orientation;
    Animal animals[2][2];

protected:
    virtual void print(ostream& o) const;

public:
    SplitFour(Animal[2][2]);

    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow();
    virtual void printRow(EvenOdd);
    virtual Animal getAnimal(int);
};

#endif
