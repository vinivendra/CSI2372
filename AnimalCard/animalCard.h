
#ifndef animalCard_h
#define animalCard_h


#include <iostream>


using namespace std;


enum class Orientation { UP = 0, DOWN = 1 };

enum class EvenOdd { EVEN = 0, ODD = 1, DEFAULT };

// Added all to take into account the start card
enum class Animal {
    BEAR = 1,
    DEER = 2,
    HARE = 3,
    MOOSE = 4,
    WOLF = 5,
    ALL = 6
};

char charForAnimal(Animal animal);
Animal animalForChar(char animal);

class AnimalCard {

protected:
    virtual void print(ostream& o) const = 0;

public:
    virtual void setOrientation(Orientation) = 0;
    virtual void setRow(EvenOdd) = 0;
    virtual EvenOdd getRow() const = 0;
    virtual void printRow(EvenOdd) const = 0;
    virtual Animal getAnimal(int) const = 0;

    virtual void writeToFile(ostream& o) {
        print(o);
        setRow((EvenOdd)(!(bool)getRow()));
        print(o);
    }

    inline friend ostream&
        operator<<(ostream& o, const AnimalCard& a) {
        a.print(o);
        return o;
    }
};


#endif
