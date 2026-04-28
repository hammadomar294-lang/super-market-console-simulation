#ifndef CARTITEM_H
#define CARTITEM_H


#include <string>
#include <stdexcept>
#include "classes/domain/Product.h"
using namespace std;

class CartItem
{
private:
    Product product;
    int Amount;
    // if failed throws invalid argument
    static int isValidAmount(int amount);
public:
    CartItem(const Product &product , int amount , bool operation);

    const Product &GetProduct() const;
    int GetAmount() const;
    int GetProductId() const;
    
};
#endif
