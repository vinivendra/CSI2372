#ifndef deck_h
#define deck_h

#include <vector>
#include <memory>
#include <iostream>


template <class T>
class Deck: public std::vector<std::shared_ptr<T>> {
public:
	std::shared_ptr<T> draw() {
		std::shared_ptr<T> result = this->back();
		this->pop_back();
		return result;
	};
};


#endif
