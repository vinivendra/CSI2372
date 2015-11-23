#include "table.h"
#include <algorithm>

// Creating a table to place the cards
Table::Table() {
    for (int i = 0; i < 103; i++) {
        for (int j = 0; j < 103; j++) {
            cardBoard[i][j] = nullptr;
        }
    }
}

// Adding a card to the table
int Table::addAt(std::shared_ptr<AnimalCard> card, int row, int col) {

    // Used once we will have a startCard class to start the game
    /*if (board[row][col] != 0) return 0;
    else {
        int m = nbMatches(card, row, col);
        if (m != 0) {
            cardBoard[row][col] = card;
            board[row][col] = 1;
        }
        return m;
    }*/
    cardBoard[row][col] = card;
    return 0;
}

// returning the number of cards that match the card at the given indices
int Table::nbMatches(int row, int col) {
    int m = 0;
    if (row - 1 >= 0 && cardBoard[row - 1][col] != nullptr) {
        if (cardBoard[row - 1][col]->getAnimal(2)
                == cardBoard[row][col]->getAnimal(0)
            || cardBoard[row - 1][col]->getAnimal(3)
                   == cardBoard[row][col]->getAnimal(1))
            m++;
    }
    if (col - 1 >= 0 && cardBoard[row][col - 1] != nullptr) {
        if (cardBoard[row][col - 1]->getAnimal(1)
                == cardBoard[row][col]->getAnimal(0)
            || cardBoard[row][col - 1]->getAnimal(3)
                   == cardBoard[row][col]->getAnimal(2))
            m++;
    }
    if (col + 1 < 103 && cardBoard[row][col + 1] != nullptr) {
        if (cardBoard[row][col + 1]->getAnimal(0)
                == cardBoard[row][col]->getAnimal(1)
            || cardBoard[row][col + 1]->getAnimal(2)
                   == cardBoard[row][col]->getAnimal(3))
            m++;
    }
    if (row + 1 < 103 && cardBoard[row + 1][col] == nullptr) {
        if (cardBoard[row + 1][col]->getAnimal(0)
                == cardBoard[row][col]->getAnimal(2)
            || cardBoard[row + 1][col]->getAnimal(1)
                   == cardBoard[row][col]->getAnimal(3))
            m++;
    }
    return m;
}

// Printing the table
void Table::print() {

    int minCol = 102, minRow = 102, maxRow = 0, maxCol = 0;

    // Getting the max and min index non empty in the table
    for (int i = 0; i != 103; i++) {
        for (int j = 0; j != 103; j++) {
            if (cardBoard[i][j] != nullptr) {
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
            if (cardBoard[i][j] != nullptr) {
                if (maxCol < j)
                    maxCol = j;
                if (maxRow == 0)
                    maxRow = i;
                break;
            }
        }
    }
    // Calculating the limit for the display screen
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
        std::cout << "Empty table!!" << std::endl;
    else {
        std::cout << "  ";
        for (int k = minRow; k != maxRow + 1; k++) {
            std::cout << k << "  ";
        }
        std::cout << std::endl;
        for (int i = minRow; i != minRow + (maxRow - minRow + 1) * 3; i++) {
            if ((i - minRow) % 3 == 0)
                std::cout << i - 2 * ((i - minRow) / 3) << " ";
            else
                std::cout << "   ";
            for (int j = minCol; j != maxCol; j++) {
                if ((i - minRow) % 3 == 2)
                    std::cout << "  ";
                else {
                    if (cardBoard[minRow + (i - minRow) / 3][j] != nullptr)
                        cardBoard[minRow + (i - minRow) / 3][j]->printRow(
                            EvenOdd((i - minRow) % 3));
                    else
                        std::cout << "  ";
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
}

std::shared_ptr<AnimalCard> Table::pickAt(int row, int col) {
    return nullptr;
};
bool Table::win(std::string& animal) {
    return false;
};