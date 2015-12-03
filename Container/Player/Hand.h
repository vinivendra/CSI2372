#ifndef hand_hpp
#define hand_hpp

#include "../../AnimalCard/animalCard.h"
#include <memory>
#include <vector>


using namespace std;


class Hand {
	vector<shared_ptr<AnimalCard>> hand;
protected:
	virtual void print(ostream& o) const;

public:
	Hand& operator+=(shared_ptr<AnimalCard>);
	Hand& operator-=(shared_ptr<AnimalCard>);
	shared_ptr<AnimalCard> operator[](int);
	int noCards();

    void writeToFile(ostream& o) const;

	inline friend ostream&
		operator<<(ostream& o, const Hand& hand) {
		hand.print(o);
		return o;
	}
};

#endif
