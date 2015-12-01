#ifndef splitTwo_hpp
#define splitTwo_hpp

#include "animalCard.h"

class SplitTwo :AnimalCard {
	EvenOdd row;
	Orientation orientation;
	Animal animals[2];

protected:
	virtual void print(ostream& o) const;

public:
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual EvenOdd getRow();
	virtual void printRow(EvenOdd);

	virtual Animal getAnimal(int);
	SplitTwo(Animal[2]);
};

#endif

