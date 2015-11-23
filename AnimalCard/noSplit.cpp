#include "noSplit.h"

NoSplit::NoSplit(Animal a) :AnimalCard() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			this->animals[i][j] = a;
		}
	}
}