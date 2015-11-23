#ifndef table_h
#define table_h

#include "../AnimalCard/animalCard.h"
#include <memory>


class Table {

	std::shared_ptr<AnimalCard> cardBoard[103][103];

public:
	Table();
	int nbMatches(int, int);
	int addAt(std::shared_ptr<AnimalCard>, int row, int col);
	//Table& operator+=(std::shared_ptr<ActionCard>);
	//Table& operator-=(std::shared_ptr<ActionCard>);
	std::shared_ptr<AnimalCard> pickAt(int row, int col);
	bool win(std::string& animal);
	void print();

};

#endif
