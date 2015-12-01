

#include <iostream>

#include "AnimalCard/animalCard.h"
#include "Container/Table/table.h"
#include "Container/AnimalCardFactory/AnimalCardFactory.h"
#include "Container/Player/player.h"
#include "Container/Deck/deck.h"

#include <vector>

using namespace std;


int main(int argc, const char *argv[]) {

	//Game loop

	cout << "How many players are playing? (2-5 players) ";
	int i = 0;
	while(i == 0)
		cin >> i;
	cout << endl;
	AnimalCardFactory::getFactory();
	Player* playerList = new Player[i];
	string name;
	for (int j = 0; j != i; j++) {
		cout << "Name of player " << j + 1 << ": ";
		cin >> name;
		playerList[j].setName(name);
		cout << endl;
	}
	//Or load from file

	bool playerHasWon = false;
	Table gameBoard;
	int nbdraws[5]{ 0,0,0,0,0 };

	while (!playerHasWon) {
		//If pause save game to file and exit
		for (int k = 0; k != i; k++) {
			cout << "Table: " << endl;
			gameBoard.print();
			for (int n = 0; n != nbdraws[k];n++)
				playerList[k].yourHand += AnimalCardFactory::getFactory()->getDeck().draw();
			cout << "Player: "<< playerList[k].getName() << endl;
			cout << playerList[k] << endl;
			int c = -1,x,y;
			do {
				cout << "Which card do you want to play? ";
				while(c<0 || c>playerList[k].yourHand.noCards()-1)
					cin >> c;
				cout << endl;
				cout << "Where do you want to play it? \nX coordonnate & Enter & Y coordonnate & Enter!";
				cin >> x >> y;
				cout << endl;
				nbdraws[k] = gameBoard.addAt(playerList[k].yourHand[c], y, x);
			} while ( nbdraws[k] == 0);
			playerList[k].yourHand -= playerList[k].yourHand[c];
			//If action card do the necessary!
			for (int m = 0; m != i; m++) {
				if (gameBoard.win(playerList[m].getName()))
					playerHasWon = true;
			}
		}
	}
    return 0;
}
