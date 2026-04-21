#include <string>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{

private :
    int Id;
    string Name;
    double Price;
    int Quantity;
    // TODO: add category class
    static int NextId;
    


public :
    // id
    int GetId() const;
    void SetId(int id);
    // name
    string GetName() const;
    void SetName(const string &name);
    // price
    double GetPrice() const;
    void SetPrice(double price);
    // quantity
    int GetQuantity() const;
    void SetQuantity(int quantity);
    // constructor
    Product(int id , const string &name , double price , int quantity);

    // business logic
    bool Sell(int amount);
    bool ReName(const string &new_name);
    bool AddStock(int quantity);

    // helpers
    bool isSufficient(int amount) const;
    bool isOutOfStock() const;
    bool NeedReStock() const;

   static void SyncIdGenerator(int next_id);

};


#endif