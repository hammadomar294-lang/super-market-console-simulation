#include "classes/domain/Product.h"

using namespace std;

int Product::NextId = 1;


#pragma region helpers

int Product::ValidateId(int id)
{
    if (id <= 0)
        throw invalid_argument("invalid product id");

    return id;
}
string Product::ValidateName(const string& name)
{
    if (name.empty())
        throw invalid_argument("product name cannot be empty");

    return name;
}
double Product::ValidatePrice(double price)
{
    if (price < 0)
        throw invalid_argument("invalid price");

    return price;
}
int Product::ValidateQuantity(int quantity)
{
    if (quantity < 0)
        throw invalid_argument("invalid quantity");

    return quantity;
}

#pragma endregion

#pragma region getters and setters

int Product::GetId() const
{
    return Id;
}

string Product::GetName() const
{
    return Name;
}

void Product::SetName(const string& name)
{
    Name = ValidateName(name);
}
double Product::GetPrice() const
{
    return Price;
}

void Product::SetPrice(double price)
{
    Price = ValidatePrice(price);
}
int Product::GetQuantity() const
{
    return Quantity;
}

void Product::SetQuantity(int quantity)
{
    Quantity = ValidateQuantity(quantity);
}

#pragma endregion

// constructors
// new product constructor
Product::Product (const string &name, double price, int quantity , Category& category)
{
    Id = NextId++;
    Name = ValidateName(name);
    Price = ValidatePrice(price);
    Quantity = ValidateQuantity(quantity);
    Category = category;
}
// existing product constructor
Product::Product (int id ,const string &name, double price, int quantity , Category& category)
{
    Id = ValidateId(id);
    Name = ValidateName(name);
    Price = ValidatePrice(price);
    Quantity = ValidateQuantity(quantity);
    Category = category;
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

void Product::SyncProductId(int max_id)
{
    if (max_id <= 0) return;

    if (max_id >= NextId)
        NextId = max_id + 1;
}

#pragma endregion

#pragma region bussiness

void Product::Sell(int amount)
{
    if (amount <= 0 || !isSufficient(amount))
        throw runtime_error("invalid amount");
    
    Quantity -= amount;
}

void Product::ReName(const string &new_name)
{
    if (new_name.empty())
        throw runtime_error("name is empty");
    Name = new_name;
    
}

void Product::AddStock(int quantity)
{
    if (quantity <= 0 || quantity > category.GetMaxAmount() - Quantity)
        throw runtime_error("invalid amount");
    Quantity += quantity
}

double Product::GetSalesPrice() const
{
    return Price * category.GetTax() / 100.0;
}

const Category &Product::GetCategory() const
{
    return category;
}

#pragma endregion


