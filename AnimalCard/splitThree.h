#ifndef splitThree_hpp
#define splitThree_hpp

#include "animalCard.h"

class SplitThree :AnimalCard {
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
	SplitThree(Animal[2][2]);
};

#endif
