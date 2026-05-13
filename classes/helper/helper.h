#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <stdexcept>
#include <unordered_map>
#include <iostream>
#include <limits>


#include "../domain/Product.h"
#include "../domain/Category.h"
#include "../domain/CartItem.h"

using namespace std;

class helper
{
private:
    
public:
    static void GoBack();
    static void Pause();
    static void ClearScreen();

    static bool Confirm();

    static void PrintLine();

    static string AskForString(string msg);
    static int AskForInt(string msg);
    static double AskForDouble(string msg);

    static int GetProductIdByName(const string & name , const unordered_map <int , Product> & products);
    static bool DoesProductExist(const string & name , const unordered_map <int , Product> & products);
    
    static int GetCategoryIdByName(const string & name , const unordered_map <int , Category> & categories);
    static bool DoesCategoryExist(const string & name , const unordered_map <int , Category> & categories);
};

#endif