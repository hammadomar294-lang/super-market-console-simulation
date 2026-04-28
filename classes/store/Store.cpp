#include "Store.h"

void Store::AddToCart(Customer &customer, int product_id, int amount)
{
    Product &product = inventory.GetProduct(product_id);
    if (!product.isSufficient(amount))
        throw runtime_error("Not enough stock");

    if (product.GetSalesPrice(amount) > customer.GetBudget())
        throw runtime_error("Customer cannot afford this product");
        
    customer.GetCart().AddProduct(product , amount);
}