#ifndef splitFour_h
#define splitFour_h


#include "animalCard.h"


class SplitFour : public AnimalCard {
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

    // Virtual Constructor Idiom
    SplitFour(Animal[2][2]);
    SplitFour (SplitFour const &);
    SplitFour* create() const;
    SplitFour* clone() const;
};


#endif
