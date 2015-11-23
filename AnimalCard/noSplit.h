#ifndef noSplit_hpp
#define noSplit_hpp


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

	virtual Animal getAnimal(int);
	SplitFour(Animal[2][2]);
};


#endif

