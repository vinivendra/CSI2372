#ifndef noSplit_h
#define noSplit_h


#include "animalCard.h"


class NoSplit : public AnimalCard {

protected:
    Animal animal;
    EvenOdd row;
    Orientation orientation;

protected:
    virtual void print(ostream& o) const;

public:
    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow();
    virtual void printRow(EvenOdd);

    Animal getAnimal(int);
    NoSplit(Animal);
};


#endif
