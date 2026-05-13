#ifndef STORE_H
#define STORE_H


#include <string>
#include <stdexcept>
#include <queue>
#include <vector>
#include <utility>

#include "../store/Inventory.h"
#include "../BST_analytics/Analyzer.h"
#include "../domain/Order.h"
#include "../domain/user/customer.h"
#include "../domain/Product.h"
using namespace std;
class Store
{

public:
    Inventory inventory;
    Analyzer analyzer;
    queue<Order> OrderQueue;
    
    Store();

    #pragma region customer functions

    void AddToCart(Customer & customer , int product_id , int amount);
    Order CheckOut(Customer & customer);

    // to display
    vector <Product> GetProductsAscending() const;
    vector <Product> GetProductsDescending() const;
    vector <Product> GetProductsByCategory(int category_id);
    vector <Product> GetProductsWithinRange(double low , double high);
    
    const Product & GetMostExpensive() const; // both returns the ids from analyzer
    const Product & GetCheapest() const;
    
    const vector <CartItem> & ShowCartItems(const Customer & customer) const;
    void ClearCart(Customer & customer);

    #pragma endregion

    #pragma region manager functions
    
    void AddProduct(const Product & product);
    void ReMoveProduct(int product_id);

    void ReNameProduct(int product_id , const string & new_name);
    void ReStockProduct(int product_id , int amount);
    void ChangeProductPrice(int product_id , double new_price);

    vector <Product>  LowStockProducts() const;

    void AddCategory(const Category & category);

    void ReNameCategory(int category_id , const string & new_name);
    void ReStockCategory(int category_id); // restock to the max
    
    const Product & MostSold() const;
    const Product & LeastSold() const;
    vector < pair<Product , int> >  AscendingSales()  const;
    vector < pair<Product , int> >  DescendingSales()  const;

    #pragma endregion
    
    bool CanAffordCart(const Customer & customer) const;
    bool IsCartEmpty(const Customer & customer) const;

    void EnqueueOrder(Order & order);
    void DequeueOrder();
    //   total   , number of items 
    pair <double , int> CalculateTotalAndNumberOfItems(const Customer & customer) const;
    
    
};

#endif


