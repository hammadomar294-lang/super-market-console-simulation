#ifndef CART_H
#define CART_H


#include <vector>
#include <string>
#include "classes/domain/CartItem.h"
#include <stack>

using namespace std;

class Cart
{
private:


    struct Action
    {
        CartItem Item;
        bool Operation;

        Action(const CartItem &item , bool operation)
        {
            Item = item;
            Operation = operation;
        }
    };

    Action MakeAction(const CartItem &item , bool operation);
    
    vector<CartItem> CartItemVector;
    
    stack<Action> Undo;   
    stack<Action> Redo;
    
    

public:

    void AddProduct(const Product &product , int amount);
                        //number of product when they are displayed
    bool RemoveProduct(int product_number);

    bool UndoLastItem();
    bool RedoLastItem();

    double GetTotalPrice() const;

    void Clear();
    bool Empty() const;
    const vector<CartItem>& GetItemsVector() const;
};
#endif
