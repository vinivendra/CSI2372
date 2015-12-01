#ifndef hand_hpp
#define hand_hpp

#include "../../AnimalCard/animalCard.h"
#include <memory>
#include <vector>

class Hand {
	std::vector<std::shared_ptr<AnimalCard>> hand;
protected:
	virtual void print(std::ostream& o) const;

public:
	Hand& operator+=(std::shared_ptr<AnimalCard>);
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[](int);
	int noCards();

	inline friend std::ostream&
		operator<<(std::ostream& o, const Hand& hand) {
		hand.print(o);
		return o;
	}
};

#endif
