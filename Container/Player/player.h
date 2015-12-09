#ifndef player_hpp
#define player_hpp

#include "Hand.h"
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

    inline friend ostream&
        operator<<(ostream& o, const Player& player) {
        player.print(o);
        return o;
    }
};

#endif
