#ifndef player_hpp
#define player_hpp

#include "Hand.h"
#include "../AnimalCardFactory/AnimalCardFactory.h"
#include <string>


using namespace std;


class Player {
    static int nextAnimal;

    string secretAnimal;
    string playerName;

protected:
    virtual void print(ostream& o) const;

public:
    Hand yourHand;
    Player();
    void setupAndDrawCards();
    string swapSecretAnimal(string&);
    string getSecretAnimal();
    void setName(string);
    string getName();

    void writeToFile(ostream& o);

    inline friend istream& operator>>(istream& file, Player& player) {
        string name;
        string secretAnimal;
        int numberOfCards;

        getline(file, name);
        getline(file, name);
        file >> secretAnimal;
        file >> numberOfCards;

        player.playerName = name;
        player.secretAnimal = secretAnimal;

        for (int j = 0; j < numberOfCards; j++) {
            string cardString;
            file >> cardString;

            shared_ptr<AnimalCard> card =
                AnimalCardFactory::createCard(cardString);
            
            player.yourHand += card;
        }
        
        return file;
    }

    inline friend ostream& operator<<(ostream& o, const Player& player) {
        player.print(o);
        return o;
    }
};

#endif
