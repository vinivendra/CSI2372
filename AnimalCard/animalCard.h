#ifndef animalCard_hpp
#define animalCard_hpp


#include <iostream>


using namespace std;


enum class Orientation { UP, DOWN };

enum class EvenOdd { EVEN=0, ODD=1, DEFAULT };

enum class Animal { BEAR, DEER, HARE, MOOSE, WOLF };

char charForAnimal(Animal animal);


class AnimalCard {

protected:
    virtual void print(ostream& o) const = 0;

public:
    virtual void setOrientation(Orientation) = 0;
    virtual void setRow(EvenOdd) = 0;
    virtual EvenOdd getRow() = 0;
    virtual void printRow(EvenOdd) = 0;
	virtual Animal getAnimal(int) = 0;

    inline friend std::ostream&
        operator<<(std::ostream& o, const AnimalCard& a) {
        a.print(o);
        return o;
    }
};


#endif
