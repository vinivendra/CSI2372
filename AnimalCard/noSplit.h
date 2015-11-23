#ifndef noSplit_h
#define noSplit_h


#include "animalCard.h"


class NoSplit : AnimalCard {
	Animal animal;

protected:
	virtual void print(ostream& o) const;

public:
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual EvenOdd getRow();
	virtual void printRow(EvenOdd);

	Animal getAnimal();
	NoSplit(Animal);
};


#endif

