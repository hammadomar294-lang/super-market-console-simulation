#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <utility>

#include "../domain/Product.h"
#include "../domain/Category.h"
#include "../domain/user/customer.h"
#include "../helper/helper.h"

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
    vector <int> ShowProducts(const unordered_map<int , Product> & products);
    vector <int> ShowProducts(const vector< Product> & products);

    // customer
    
    void ShowCustomerMenu(const Customer& customer);

    // manager
    void ShowMangerMenu(const vector<Product>& low_stock_products);

    void ShowCategories(const unordered_map<int , Category> & categories);
    void ShowManagerProductsOptionsMenu();
    void ShowCategoriesMenu();
    void ShowAnalyticsMenu();

    void ShowSales(const vector<pair<Product, int>> & sales); // product and amount

};

#endif