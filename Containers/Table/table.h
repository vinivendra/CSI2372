#ifndef table_hpp
#define table_hpp


#include "splitFour.h"
#include <memory>

class Table {

	std::shared_ptr<SplitFour> cardBoard[103][103];
	char board[103][103];

public:
	Table();
	int nbMatches(std::shared_ptr<SplitFour>, int, int);
	int addAt(std::shared_ptr<SplitFour>, int row, int col);
	//Table& operator+=(std::shared_ptr<ActionCard>);
	//Table& operator-=(std::shared_ptr<ActionCard>);
	std::shared_ptr<AnimalCard> pickAt(int row, int col);
	bool win(std::string& animal);
	void print();

};

#endif
