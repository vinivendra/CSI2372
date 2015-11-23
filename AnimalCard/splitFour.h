#ifndef splitFour_h
#define splitFour_h


#include "animalCard.h"


class SplitFour : AnimalCard {
    EvenOdd row;
    Orientation orientation;
    Animal animals[2][2];

protected:
    virtual void print(ostream& o) const;

public:
    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow();
    virtual void printRow(EvenOdd);

	Animal getAnimal(int);
    SplitFour(Animal[2][2]);
};


#endif
