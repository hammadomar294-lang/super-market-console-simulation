#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

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
    void ShowProductsOptions();
    

    // manager
    void ShowMangerMenu(const vector<Product>& low_stock_products);

    void ShowProductsMenu();
    void ShowCategoriesMenu();
    void ShowAnalyticsMenu();

};

#endif