#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <stdexcept>
#include <unordered_map>


#include <classes/domain/Product.h>
#include <classes/domain/CartItem.h>



class helper
{
private:
    
public:
    static int GetProductIdByName(const string & name , const unordered_map <int , Product> & products);
    static int GetCategoryIdByName(const string & name , const unordered_map <int , Category> & categories);
};

#endif