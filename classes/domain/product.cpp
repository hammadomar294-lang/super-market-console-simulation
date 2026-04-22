#include "product.h"

using namespace std;

int Product::NextId = 1;
#pragma region getters and setters

int Product::GetId() const
{
    return Id;
}

void Product::SetId(int id)
{
    if (id < 0) return;
    Id = id;
}

string Product::GetName() const
{
    return Name;
}

void Product::SetName(const string &name)
{
    if (name.empty()) return;
    Name = name;
}

double Product::GetPrice() const
{
    return Price;
}

void Product::SetPrice(double price)
{
    if (price < 0) return;
    Price = price;
}

int Product::GetQuantity() const
{
    return Quantity;
}

void Product::SetQuantity(int quantity)
{
    if (quantity < 0) return;
    Quantity = quantity;
}


#pragma endregion

// constructors
// new product constructor
Product::Product (const string &name, double price, int quantity)
{
    Id = NextId++;
    Name = name;
    Price = price;
    Quantity = quantity;
}
// existing product constructor
Product::Product (int id ,const string &name, double price, int quantity)
{
    Id = id;
    Name = name;
    Price = price;
    Quantity = quantity;
}

#pragma region helpers

bool Product::isSufficient(int amount) const
{
    return GetQuantity() >= amount;
}

bool Product::isOutOfStock() const
{
    return Quantity == 0;
}

bool Product::NeedReStock() const
{
    return Quantity <= 3;
}

void Product::SyncIdGenerator(int next_id)
{
    if (next_id <= 0) return;
    NextId = next_id;
}

#pragma endregion

#pragma region bussiness

bool Product::Sell(int amount)
{
    if (amount <= 0)
        return false;
    if (!isSufficient(amount))
        return false;
    Quantity -= amount;
    return true;
}

bool Product::ReName(const string &new_name)
{
    if (new_name.empty()) return false;
    Name = new_name;
    return true;
}

bool Product::AddStock(int quantity)
{
    if (quantity < 0) return false;
    Quantity += quantity;
    return true;
}

#pragma endregion

