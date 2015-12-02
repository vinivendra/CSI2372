
#ifndef queryResult_h
#define queryResult_h

#include <string>


using namespace std;


class QueryResult {
    int a, b, c, d;
public:
    QueryResult(int = 0, int = 0, int = 0, int = 0);
    void getCoordinates(int&, int&) const;
    void getSecondCoordinates(int&, int&) const;
    void getPlayer(int&) const;
};


#endif
