#ifndef table_hpp
#define table_hpp


#include "../../AnimalCard/animalCard.h"
#include <memory>


using namespace std;


class IllegalPick : runtime_error {
    int x, y;
public:
    IllegalPick(int, int);
    virtual const char* what() const throw();
};

class IllegalPlacement : runtime_error {
    int x, y;
public:
    IllegalPlacement(int, int);
    virtual const char* what() const throw();
};


class Table {

    std::shared_ptr<AnimalCard> cardBoard[103][103];
    char board[103][103];
    int maxRow, maxCol, minRow, minCol;

public:
    Table(shared_ptr<AnimalCard> startStack);

    shared_ptr<AnimalCard> getStartStack();
    int nbMatches(shared_ptr<AnimalCard>, int, int);
    int addAt(shared_ptr<AnimalCard>, int row, int col);
    // Table& operator+=(std::shared_ptr<ActionCard>);
    // Table& operator-=(std::shared_ptr<ActionCard>);
    std::shared_ptr<AnimalCard> pickAt(int row, int col);
    bool win(string& animal);
    void print();
};

#endif
