#include <string>
#include "Category.h"
#include <stdexcept>
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
    Category category;
    
    static int NextId;

    static int ValidateId(int id);
    static string ValidateName(const string& name);
    static double ValidatePrice(double price);
    static int ValidateQuantity(int quantity);

public :
    // id
    int GetId() const;
    // name
    string GetName() const;
    void SetName(const string &name);
    // price
    double GetPrice() const;
    void SetPrice(double price);
    // quantity
    int GetQuantity() const;
    void SetQuantity(int quantity);
    // sales price
    double GetSalesPrice() const;
    
    const Category & GetCategory() const;


    // constructors
    Product(int id , const string &name , double price , int quantity , const Category & category); // for existing products
    Product(const string &name , double price , int quantity , const Category & category); // for new products

    // business logic
    void Sell(int amount);
    void ReName(const string &new_name);
    void AddStock(int quantity);

    // helpers
    bool isSufficient(int amount) const;
    bool isOutOfStock() const;
    bool NeedReStock() const;

   static void SyncProductId(int max_id);

};


#endif