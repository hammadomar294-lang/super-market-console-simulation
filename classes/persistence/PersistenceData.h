#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <unordered_map>
#include <iostream>

#include "../domain/Category.h"
#include "../domain/Product.h"

using namespace std;


class PersistenceData
{
private :
    static int CategoryMaxId;
    static int ProductMaxId;
    static const Category &FindCategory(const unordered_map<int , Category> & map , int category_id);
public:
               //Name   Password
    static pair<string , string> LoadManagerData();

    // TODO: load and save products
    static unordered_map<int , Product>  LoadProducts(const unordered_map<int , Category> & categories);
    static void SaveProducts(const unordered_map<int , Product> & products);

    // TODO: load and save categories
    static unordered_map<int , Category> LoadCategories();
    static void SaveCategories(const unordered_map<int , Category> & categories);

    // TODO: load and save history order
    static unordered_map<int , int> LoadSales();
    static void SaveSales(const unordered_map<int , int> & sales);
}; 

#endif
