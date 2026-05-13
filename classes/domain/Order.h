#ifndef ORDER_H
#define ORDER_H


#include <string>
#include "../domain/CartItem.h"
#include <vector>
using namespace std;


class Order
{
private:
    vector<CartItem> Items;
    double Total;
    
    static double CalculateTotal(const vector<CartItem> & items);

    static const vector<CartItem> & ValidateItems(const vector<CartItem> & items);
public:
    Order(const vector<CartItem> & items);

    double GetTotal() const;
    const vector<CartItem> & GetItemsVector() const;
};

#endif