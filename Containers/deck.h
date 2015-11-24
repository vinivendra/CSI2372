#ifndef deck_h
#define deck_h

#include <vector>


using namespace std;


template <class T>
class Deck: public vector<T> {
public:
    std::shared_ptr<T> draw();
};


#endif
