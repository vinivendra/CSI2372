
#ifndef noSplit_h
#define noSplit_h


#include "animalCard.h"


class NoSplit : public AnimalCard {

protected:
    Animal animal;
    EvenOdd row;

    virtual void print(ostream& o) const;

public:
    NoSplit(Animal);

    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow() const;
    virtual void printRow(EvenOdd) const;
    virtual Animal getAnimal(int) const;
};

#endif
