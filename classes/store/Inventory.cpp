#include "../store/Inventory.h"
#include "Inventory.h"

const unordered_map<int, Product> &Inventory::GetProductMap() const
{
    return ProductMap;
}

const unordered_map<int, Category> &Inventory::GetCategoryMap() const
{
    return CategoryMap;
}

const unordered_map<int, int> &Inventory::GetSalesMap() const
{
    return SalesMap;
}

bool Inventory::HasProduct(int product_id) const
{
    return ProductMap.find(product_id) != ProductMap.end();
}

Product &Inventory::GetProduct(int product_id) 
{
    if (HasProduct(product_id))
        return ProductMap.at(product_id);
    else
        throw runtime_error("Product doesn't exist");
    
}

const Product &Inventory::GetProduct(int product_id) const
{
    if (HasProduct(product_id))
        return ProductMap.at(product_id);
    else
        throw runtime_error("Product doesn't exist");
}


void Inventory::RestockProduct(int product_id, int amount)
{
    GetProduct(product_id).AddStock(amount);
}

void Inventory::DecreaseStock(int product_id, int amount)
{
    GetProduct(product_id).Sell(amount);
}

vector <Product> Inventory::GetLowStockProducts() const
{
    vector <Product> low_stock;
    for (const auto & pair : ProductMap)
    {
        if (pair.second.NeedReStock())
            low_stock.push_back(pair.second);
    }
    return low_stock;
}

void Inventory::AddProduct(const Product &product)
{
    if (HasProduct(product.GetId()))
        throw runtime_error("product allready exist"); 

    ProductMap.emplace(product.GetId() , product) ;
}

void Inventory::RemoveProduct(int id)
{
    if (!HasProduct(id))
        throw runtime_error("product does not exist");
    ProductMap.erase(id);
}

void Inventory::RenameProduct(int id, const string &new_name)
{
    if (HasProduct(id))
        GetProduct(id).ReName(new_name);
    else
        throw runtime_error("Product does not exist");
}

void Inventory::ChangePrice(int product_id , double new_price)
{
    if (HasProduct(product_id))
        ProductMap.at(product_id).SetPrice(new_price);
    
    else
        throw runtime_error("Product does not exist");
    
}

bool Inventory::HasCategory(int category_id) const
{
    return CategoryMap.find(category_id) != CategoryMap.end();
}

Category &Inventory::GetCategory(int category_id)
{
    if (HasCategory(category_id))
        return CategoryMap.at(category_id);
    else
        throw runtime_error("category does not exist");
}

void Inventory::RestockCategory(int category_id)
{
    if (!HasCategory(category_id))
        throw runtime_error("category does not exist");

    int quantity = GetCategory(category_id).GetMaxAmount();
    int counter = 0 ;
    for (auto & pair : ProductMap)
    {
        if (pair.second.GetCategory().GetCategoryId() == category_id)
        {
            if (pair.second.GetQuantity() < pair.second.GetCategory().GetMaxAmount())
            {
                pair.second.SetQuantity(quantity);
                counter++;
            }
            else if (counter == 0)
                throw runtime_error("category allready stocked");
        }
    }
}

void Inventory::AddCategory(const Category &category)
{
    if (HasCategory(category.GetCategoryId()))
        throw runtime_error("category allready exist");

    CategoryMap.emplace(category.GetCategoryId() , category);
}

void Inventory::RemoveCategory(int category_id)
{
    if (!HasCategory(category_id))
        throw runtime_error("category does not exist");

    for (auto i = ProductMap.begin(); i != ProductMap.end(); )
    {
        if (i->second.GetCategory().GetCategoryId() == category_id)
            i = ProductMap.erase(i);
        else
            ++i;
    }

    CategoryMap.erase(category_id);
}

void Inventory::RenameCategory(int id, const string &new_name)
{
    GetCategory(id).SetCategoryName(new_name);
}

unordered_map<int, Product> Inventory::GetProductMapByCategoryId(int category_id) const
{
    if (!HasCategory(category_id))
        throw runtime_error("category does not exist");

    unordered_map<int, Product> products;
    for (const auto & pair : ProductMap)
    {
        if (pair.second.GetCategory().GetCategoryId() == category_id)
            products.emplace(pair.first , pair.second) ;
    }
    return products;
}

void Inventory::AddSale(int product_id, int amount)
{
    SalesMap[product_id] += amount; 
}

Inventory::Inventory()
{
    CategoryMap = PersistenceData::LoadCategories();
    ProductMap = PersistenceData::LoadProducts(CategoryMap);
    SalesMap = PersistenceData::LoadSales();
}
