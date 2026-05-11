#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <utility>

#include "classes/domain/Product.h"
#include "classes/domain/Category.h"
#include "classes/domain/user/customer.h"
#include "classes/helper/helper.h"

using namespace std;

class Menus
{
private:
    void ShowCustomerOptions();
    void ShowCustomerHeader(const Customer& customer);
    void ShowCartItems(const Customer & customer);

    void ShowManagerOptions();
    void ShowLowStockProducts(const vector<Product> & low_stock_products);

public:
    void ShowMainMenu();

    // both
    void ShowProducts(const unordered_map<int , Product> & products);
    void ShowProducts(const vector< Product> & products);

    // customer
    
    void ShowCustomerMenu(const Customer& customer);
    void ShowCustomerOptions();
    

    // manager
    void ShowMangerMenu(const vector<Product>& low_stock_products);

    void ShowManagerProductsOptionsMenu();
    void ShowCategoriesMenu();
    void ShowAnalyticsMenu();

    void ShowSales(const vector < pair <Product , int> > sales); // product and amount

};

#endif