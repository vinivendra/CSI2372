#ifndef player_hpp
#define player_hpp

#include "Hand.h"
#include <string>


class Player {
	std::string secretAnimal;
	std::string playerName;
	static int nextAnimal;
protected:
	virtual void print(std::ostream& o) const;
public:
	Hand yourHand;
	Player();
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	void setName(std::string);
	std::string getName();

	inline friend std::ostream&
		operator<<(std::ostream& o, const Player& player) {
		player.print(o);
		return o;
	}

};

#endif
