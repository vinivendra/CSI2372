

#ifndef SplitFour_hpp
#define SplitFour_hpp


#include "animalCard.h"


class SplitFour : AnimalCard {

protected:
    virtual void print(ostream& o) const;

public:
    virtual void setOrientation(Orientation);
    virtual void setRow(EvenOdd);
    virtual EvenOdd getRow();
    virtual void printRow(EvenOdd);

    SplitFour(Animal[2][2]);
};


#endif
