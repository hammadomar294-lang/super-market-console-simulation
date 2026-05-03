#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <unordered_map>

#include "classes/domain/Product.h"
#include "classes/domain/Category.h"
#include "classes/domain/user/customer.h"

using namespace std;

class Menus
{
public:
    static void ShowMainMenu();

    // product
    static void ShowCustomerMenu();

    static void ShowProducts(const unordered_map<int , Product> & products);
    static void ShowProducts(const vector< Product> & products);
    
    static void ShowCartItems(const Customer & customer);

    // manager
    static void ShowMangerMenu();
    static void ShowLowStockProducts(const vector<Product> & low_stock_products);

};

#endif