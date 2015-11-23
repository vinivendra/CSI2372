#ifndef noSplit_hpp
#define noSplit_hpp


#include "animalCard.h"


class NoSplit : AnimalCard {

protected:
	virtual void print(ostream& o) const;

public:
	virtual void setOrientation(Orientation);
	virtual void setRow(EvenOdd);
	virtual EvenOdd getRow();
	virtual void printRow(EvenOdd);

	NoSplit(Animal);
};


#endif

