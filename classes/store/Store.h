#ifndef STORE_H
#define STORE_H


#include <string>
#include <stdexcept>
#include <queue>
#include <vector>
#include <utility>

#include "classes/store/Inventory.h"
#include "classes/BST_analytics/Analyzer.h"
#include "classes/domain/Order.h"
#include "classes/domain/user/customer.h"

using namespace std;
class Store
{
private:
    Inventory inventory;
    Analyzer analyzer;
    queue<Order> OrderQueue;
public:

    Store();

    #pragma region customer functions

    void AddToCart(Customer & customer , int product_id , int amount);
    void CheckOut(Customer & customer);

    vector <Product> GetProducts() const;
    vector <Product> GetProductsAscending() const;
    vector <Product> GetProductsDescending() const;
    vector <Product> GetProductsByCategory(int category_id);
    vector <Product> GetProductsWithinRange(double high , double low);

    int GetMostExpensive() const; // both returns the ids from analyzer
    int GetCheapest() const;
    
    const vector <CartItem> & ShowCartItems(const Customer & customer) const;
    void ClearCart(Customer & customer);

    #pragma endregion

    #pragma region manager functions
    // all vectors are ids vectors

    void AddProduct(const Product & product);
    void ReMoveProduct(int product_id);

    void ReNameProduct(int product_id , const string & new_name);
    void ReStockProduct(int product_id , int amount);
    void ChangeProductPrice(int product_id , double new_price);

    vector <int> LowStockProducts() const;
    vector <int> OutOfStockProducts() const;


    void AddCategory(const Category & category);
    void ReMoveCategory(int category_id);

    void ReNameCategory(int category_id , const string & new_name);
    void ReStockCategory(int category_id); // restock to the max
    
    int MostSold() const;
    vector <int> NthMostSold(int n)  const;
    int LeastSold()  const;
    vector <int> AscendingSales()  const;
    vector <int> DescendingSales()  const;

    #pragma endregion
    
    bool CanAffordCart(const Customer & customer) const;
    bool IsCartEmpty(const Customer & customer) const;

    Order MakeOrder(const Customer & customer) const;

    void EnqueueOrder(const Customer & customer);
    void DequeueOrder();
    //   total   , number of items 
    pair <double , int> CalculateTotalAndNumberOfItems(const Customer & customer) const;

    void EndSession();
};

#endif


