#include "table.h"
#include <algorithm>

//Creating a table to place the cards
Table::Table() {
	std::fill(board[0] + 0, board[102] + 102, 0);
}

//Adding a card to the table
int Table::addAt(std::shared_ptr<SplitFour> card, int row, int col) {

	//Used once we will have a startCard class to start the game
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
	board[row][col] = 1;
	return 0;
}
//returning the number of card that match the given one
int Table::nbMatches(std::shared_ptr<SplitFour> card, int row, int col) {
	int m = 0;
	if (row-1>=0 && board[row - 1][col] == 1) {
		if (cardBoard[row - 1][col]->getAnimal(2) == cardBoard[row][col]->getAnimal(0) || cardBoard[row - 1][col]->getAnimal(3) == cardBoard[row][col]->getAnimal(1))
			m++;
	}
	if (col-1 >= 0 && board[row][col-1] == 1) {
		if (cardBoard[row][col-1]->getAnimal(1) == cardBoard[row][col]->getAnimal(0) || cardBoard[row][col-1]->getAnimal(3) == cardBoard[row][col]->getAnimal(2))
			m++;
	}
	if (col+1 < 103 && board[row][col+1] == 1) {
		if (cardBoard[row][col+1]->getAnimal(0) == cardBoard[row][col]->getAnimal(1) || cardBoard[row][col+1]->getAnimal(2) == cardBoard[row][col]->getAnimal(3))
			m++;
	}
	if (row+1 < 103 && board[row + 1][col] == 1) {
		if (cardBoard[row + 1][col]->getAnimal(0) == cardBoard[row][col]->getAnimal(2) || cardBoard[row + 1][col]->getAnimal(1) == cardBoard[row][col]->getAnimal(3))
			m++;
	}
	return m;
}

void Table::print() {

	int minCol = 102, minRow = 102, maxRow = 0, maxCol = 0;

	//Getting the max and min index non empty in the table
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

	//Displaying the table
	if (maxRow < minRow || maxCol < minCol)
		std::cout << "Empty table!!" << std::endl;
	else {
		std::cout << "  ";
		for (int k = minRow; k != maxRow+1; k++) {
			std::cout << k << "  ";
		}
		std::cout << std::endl;
		for (int i = minRow; i != minRow + (maxRow - minRow+1)*3; i++) {
			if ((i-minRow) % 3 == 0)
				std::cout << i - 2*((i-minRow)/3) << " ";
			else
				std::cout << "   ";
			for (int j = minCol; j != maxCol; j++) {
				if ((i-minRow) % 3 == 2)
					std::cout << "  ";
				else {
					if (board[minRow + (i - minRow) / 3][j] == 1)
						cardBoard[minRow + (i - minRow) / 3][j]->printRow(EvenOdd((i - minRow) % 3));
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