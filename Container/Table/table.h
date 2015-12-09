#ifndef table_hpp
#define table_hpp


#include "../../AnimalCard/animalCard.h"
#include "../../AnimalCard/startStack.h"
#include "../AnimalCardFactory/AnimalCardFactory.h"
#include <memory>
#include <string>


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

    shared_ptr<AnimalCard> cardBoard[103][103];
    char board[103][103];
    int maxRow, maxCol, minRow, minCol;

    void insert(shared_ptr<AnimalCard>, int row, int col);

public:
    Table();

    int nbMatches(shared_ptr<AnimalCard>, int, int);
    int addAt(shared_ptr<AnimalCard>, int row, int col);
    Table& operator+=(shared_ptr<NoSplit>);
    Table& operator-=(shared_ptr<NoSplit>);
    shared_ptr<AnimalCard> pickAt(int row, int col);
    bool win(string& animal);
    void print();

    void writeToFile(ostream& o) const;

    inline friend istream& operator>>(istream& file, Table& table) {
        int numberOfStackCards;
        file >> numberOfStackCards;

        for (int i = 0; i < numberOfStackCards; i++) {
            string cardString;
            file >> cardString;

            shared_ptr<AnimalCard> card =
                AnimalCardFactory::createCard(cardString);

            if (shared_ptr<NoSplit> noSplit =
                dynamic_pointer_cast<NoSplit>(card)) {
                table += noSplit;
            }
        }

        while (true) {
            int x, y;
            file >> x;
            file >> y;

            if (file.eof())
                break;

            string cardString;
            file >> cardString;

            shared_ptr<AnimalCard> card =
                AnimalCardFactory::createCard(cardString);
            
            table.insert(card, x, y);
        }

        return file;
    }
};

#endif
