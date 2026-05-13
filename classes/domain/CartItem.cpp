#include "../domain/CartItem.h"

using namespace std;

int CartItem::isValidAmount(int amount)
{
    if (amount <= 0 || amount > 10000) throw invalid_argument("invalid number");
    return amount;
}

CartItem::CartItem(const Product &product, int amount) : product(product),
                                                         Amount(isValidAmount(amount)) 
{
}

const Product &CartItem::GetProduct() const
{
    return product;
}

int CartItem::GetAmount() const
{
    return Amount;
}

int CartItem::GetProductId() const
{
    return product.GetId();
}


