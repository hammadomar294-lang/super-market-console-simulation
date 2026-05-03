#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <stdexcept>
#include <unordered_map>
#include <iostream>

#include <classes/domain/Product.h>
#include <classes/domain/CartItem.h>



class helper
{
private:
    
public:

    static string AskForString(string msg);
    static int AskForInt(string msg);
    static double AskForDouble(string msg);

    static int GetProductIdByName(const string & name , const unordered_map <int , Product> & products);
    static int GetCategoryIdByName(const string & name , const unordered_map <int , Category> & categories);
};

#endif