#ifndef ACTION_H
#define ACTION_H

#include "../domain/CartItem.h"

class Action
{
public:
    CartItem Item;
    bool Operation;

    Action(const CartItem& item, bool operation) : Item(item), Operation(operation)
    {}
};

#endif