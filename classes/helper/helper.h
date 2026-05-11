#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <stdexcept>
#include <unordered_map>
#include <iostream>
#include <limits>


#include "classes/domain/Product.h"
#include "classes/domain/Category.h"
#include "classes/domain/CartItem.h"

using namespace std;

class helper
{
private:
    
public:

    static void Pause();
    static void ClearScreen();

    static bool Confirm();

    static void PrintLine();

    static string AskForString(string msg);
    static int AskForInt(string msg);
    static double AskForDouble(string msg);

    static int GetProductIdByName(const string & name , const unordered_map <int , Product> & products);
    static int GetCategoryIdByName(const string & name , const unordered_map <int , Category> & categories);
};

#endif