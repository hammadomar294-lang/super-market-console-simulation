#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <unordered_map>
#include <vector>

#include "../domain/Product.h"
#include "../domain/Category.h"
#include "../persistence/PersistenceData.h"

using namespace std;    



class Inventory
{
private:
    unordered_map<int , Product> ProductMap;
    unordered_map<int , Category> CategoryMap;
    unordered_map<int , int> SalesMap; 

public:
    // read only
    const unordered_map<int , Product> & GetProductMap() const;
    const unordered_map<int , Category> & GetCategoryMap() const;
    const unordered_map<int , int> & GetSalesMap() const;

    // product helper
    bool HasProduct(int product_id) const;
    Product & GetProduct(int product_id);
    const Product & GetProduct(int product_id) const;
    

    vector <Product> GetLowStockProducts() const; // the quantity of that low stock products in store class


    void RestockProduct(int product_id , int amount);
    void DecreaseStock(int product_id , int amount);
    void ChangePrice(int product_id , double new_price);


    void AddProduct(const Product& product);
    void RemoveProduct(int id);
    void RenameProduct(int id, const string& new_name);

    
    // category helper 
    bool HasCategory(int category_id) const;
    Category & GetCategory(int category_id);

    void RestockCategory(int category_id); // restock category to max amount

    void AddCategory(const Category& category);
    void RemoveCategory(int category_id);
    void RenameCategory(int id, const string& new_name);

    unordered_map<int , Product> GetProductMapByCategoryId(int category_id) const;

    void AddSale(int product_id , int amount); // to sales map to increase the amount sold from each product id

    // constructor 
    Inventory();
};

#endif