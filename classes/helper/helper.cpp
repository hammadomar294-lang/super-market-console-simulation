#include "classes/helper/helper.h"
#include "helper.h"

int helper::GetProductIdByName(const string &name, const unordered_map<int, Product> &products)
{
    for (const auto & pair : products)
    {
        if(pair.second.GetName() == name)
            return pair.first;
    }
    throw runtime_error("product was not found try again");
}
int helper::GetCategoryIdByName(const string &name, const unordered_map<int, Category> &categories)
{
    for (const auto & pair : categories)
    {
        if (pair.second.GetCategoryName() == name)
            return pair.first;
    }
    throw runtime_error("category was not found try again");
}