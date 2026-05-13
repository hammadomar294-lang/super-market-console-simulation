#include "../domain/Order.h"

using namespace std;

double Order::CalculateTotal(const vector<CartItem> &items) 
{
    double total = 0.0;
    for (const auto & item : items)
    {
        total += item.GetProduct().GetSalesPrice() * item.GetAmount();
    }
    return total;
}
const vector<CartItem> & Order::ValidateItems(const vector<CartItem> &items) 
{
    if (items.empty())
       throw invalid_argument("order can't be empty");
    return items;
}
Order::Order(const vector<CartItem> &items) : Items(ValidateItems(items)) ,
                                                            Total(CalculateTotal(items))
{
}
double Order::GetTotal() const
{
    return Total;
}

const vector<CartItem> &Order::GetItemsVector() const
{
    return Items;
}
