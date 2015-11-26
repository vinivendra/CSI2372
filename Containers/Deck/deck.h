#ifndef deck_h
#define deck_h

#include <vector>


template <class T>
class Deck: public std::vector<T> {
public:
    std::shared_ptr<T> draw();
};


#endif
