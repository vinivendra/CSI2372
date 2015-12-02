
#include "queryResult.h"


QueryResult::QueryResult(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {
}


void QueryResult::getCoordinates(int &x, int &y) const {
    x = a;
    y = b;
}

void QueryResult::getSecondCoordinates(int &x, int &y) const {
    x = c;
    y = d;
}

void QueryResult::getPlayer(int &p) const {
    p = a;
}
