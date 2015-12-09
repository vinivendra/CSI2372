#include "table.h"
#include "../../AnimalCard/startCard.h"
#include <algorithm>
#include <sstream>


////////////////////////////////////////////////////////////////////////////////
// IllegalPick class

IllegalPick::IllegalPick(int x, int y)
    : runtime_error("division by zero"), x(x), y(y) {
}

const char* IllegalPick::what() const throw() {
    ostringstream stream = ostringstream("");
    stream << runtime_error::what() << "Position " << x << ", " << y
           << "is invalid." << endl;
    return stream.str().c_str();
}

////////////////////////////////////////////////////////////////////////////////
// IllegalPlacement class

IllegalPlacement::IllegalPlacement(int x, int y)
    : runtime_error("division by zero"), x(x), y(y) {
}

const char* IllegalPlacement::what() const throw() {
    ostringstream stream = ostringstream("");
    stream << runtime_error::what() << "Position " << x << ", " << y
           << "is invalid." << endl;
    return stream.str().c_str();
}


////////////////////////////////////////////////////////////////////////////////
// Table class

bool animalsAreEqual(Animal a, Animal b) {
    return (a == b) || a == Animal::ALL || b == Animal::ALL;
}

// Creating a table to place the cards with a start card in the middle
Table::Table() : minRow(102), minCol(102), maxRow(0), maxCol(0) {
    fill(board[0] + 0, board[102] + 102, 0);

    shared_ptr<AnimalCard> startStack
        = shared_ptr<AnimalCard>(new StartStack());
    cardBoard[52][52] = startStack;
    board[52][52] = 1;
}

// Adding a card to the table
int Table::addAt(shared_ptr<AnimalCard> card, int row, int col) {

    if (board[row][col] == 0) {
        int m = nbMatches(card, row, col);
        if (m != 0) {
            insert(card, row, col);
            return m;
        }
    }

    throw IllegalPlacement(row, col);
    return 0;
}

// Forcibly inserting a card on the table
void Table::insert(shared_ptr<AnimalCard> card, int row, int col) {
    cardBoard[row][col] = card;
    board[row][col] = 1;

    if (row < minRow)
        minRow = row;
    if (row > maxRow)
        maxRow = row;
    if (col < minCol)
        minCol = col;
    if (col > maxCol)
        maxCol = col;
}

// returning the number of card that match the given one
int Table::nbMatches(shared_ptr<AnimalCard> card, int row, int col) {
    int m = 0;
    if (row - 1 >= 0 && board[row - 1][col] == 1) {
        shared_ptr<AnimalCard> otherCard = cardBoard[row - 1][col];

        Animal a1 = otherCard->getAnimal(2);
        Animal a2 = otherCard->getAnimal(3);
        Animal b1 = card->getAnimal(0);
        Animal b2 = card->getAnimal(1);

        if (animalsAreEqual(a1, b1) || animalsAreEqual(a2, b2))
            m++;
    }
    if (col - 1 >= 0 && board[row][col - 1] == 1) {
        shared_ptr<AnimalCard> otherCard = cardBoard[row][col - 1];

        Animal a1 = otherCard->getAnimal(1);
        Animal a2 = otherCard->getAnimal(3);
        Animal b1 = card->getAnimal(0);
        Animal b2 = card->getAnimal(2);

        if (animalsAreEqual(a1, b1) || animalsAreEqual(a2, b2))
            m++;
    }
    if (col + 1 < 103 && board[row][col + 1] == 1) {
        shared_ptr<AnimalCard> otherCard = cardBoard[row][col + 1];

        Animal a1 = otherCard->getAnimal(0);
        Animal a2 = otherCard->getAnimal(2);
        Animal b1 = card->getAnimal(1);
        Animal b2 = card->getAnimal(3);

        if (animalsAreEqual(a1, b1) || animalsAreEqual(a2, b2))
            m++;
    }
    if (row + 1 < 103 && board[row + 1][col] == 1) {
        shared_ptr<AnimalCard> otherCard = cardBoard[row + 1][col];

        Animal a1 = otherCard->getAnimal(0);
        Animal a2 = otherCard->getAnimal(1);
        Animal b1 = card->getAnimal(2);
        Animal b2 = card->getAnimal(3);

        if (animalsAreEqual(a1, b1) || animalsAreEqual(a2, b2))
            m++;
    }
    return m;
}

void Table::print() {

    minCol = 102;
    minRow = 102;
    maxRow = 0;
    maxCol = 0;

    // Getting the max and min index non empty in the table
    for (int i = 0; i != 103; i++) {
        for (int j = 0; j != 103; j++) {
            if (board[i][j] == 1) {
                if (minRow == 102)
                    minRow = i;
                if (minCol > j)
                    minCol = j;
                break;
            }
        }
    }
    for (int i = 102; i != -1; i--) {
        for (int j = 102; j != -1; j--) {
            if (board[i][j] == 1) {
                if (maxCol < j)
                    maxCol = j;
                if (maxRow == 0)
                    maxRow = i;
                break;
            }
        }
    }
    if (minCol != 0)
        minCol--;
    if (maxCol != 102)
        maxCol++;
    if (minRow != 0)
        minRow--;
    if (maxRow != 102)
        maxRow++;

    // Displaying the table
    if (maxRow < minRow || maxCol < minCol)
        cout << "Empty table!!" << endl;
    else {
        cout << "   ";
        for (int k = minCol; k != maxCol + 1; k++) {
            cout << k << "  ";
        }
        cout << endl;
        for (int i = minRow; i != minRow + (maxRow - minRow + 1) * 3; i++) {
            if ((i - minRow) % 3 == 0)
                cout << i - 2 * ((i - minRow) / 3) << " ";
            else
                cout << "   ";
            for (int j = minCol; j != maxCol; j++) {
                if ((i - minRow) % 3 == 2)
                    cout << "  ";
                else {
                    if (board[minRow + (i - minRow) / 3][j] == 1)
                        cardBoard[minRow + (i - minRow) / 3][j]->printRow(
                            EvenOdd((i - minRow) % 3));
                    else
                        cout << "  ";
                }
                cout << "  ";
            }
            cout << endl;
        }
    }
}

shared_ptr<AnimalCard> Table::pickAt(int row, int col) {
    if (board[row][col] != 1 || (row == 52 && col == 52)) {
        throw IllegalPick(row, col);
    }

    shared_ptr<AnimalCard> pickedCard = cardBoard[row][col];

    cardBoard[row][col] = nullptr;
    board[row][col] = 0;

    return pickedCard;
}

bool Table::win(string& animal) {
    int nbSecretAnimalCard = 0;
    for (int i = minRow; i != maxRow; i++) {
        for (int j = minCol; j != maxCol; j++) {
            if (board[i][j]) {
                for (int k = 0; k != 4; k++) {
                    if (string(1, charForAnimal(cardBoard[i][j]->getAnimal(k)))
                        == animal) {
                        nbSecretAnimalCard++;
                        break;
                    }
                }
            }
        }
    }
    return nbSecretAnimalCard > 11;
};

Table& Table::operator+=(shared_ptr<NoSplit> card) {
    shared_ptr<StartStack> startStack
        = dynamic_pointer_cast<StartStack>(cardBoard[52][52]);
    *startStack += card;
    return *this;
}

Table& Table::operator-=(shared_ptr<NoSplit> card) {
    shared_ptr<StartStack> startStack
        = dynamic_pointer_cast<StartStack>(cardBoard[52][52]);
    *startStack -= card;
    return *this;
}

void Table::writeToFile(ostream& o) const {
    shared_ptr<StartStack> startStack
        = dynamic_pointer_cast<StartStack>(cardBoard[52][52]);
    startStack->writeToFile(o);

    for (int i = minRow; i <= maxRow; i++) {
        for (int j = minCol; j <= maxCol; j++) {
            if (i != 52 || j != 52) { // Skip the start stack
                if (board[i][j]) {
                    o << i << " " << j << endl;
                    cardBoard[i][j]->writeToFile(o);
                    o << endl;
                }
            }
        }
    }
}
