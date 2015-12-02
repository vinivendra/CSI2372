
#ifndef wolfAction_h
#define wolfAction_h

#include "actionCard.h"


class WolfAction : public ActionCard {
public:
    WolfAction();
    QueryResult query();
    void perform(Table &, Player *, QueryResult);
};

#endif
