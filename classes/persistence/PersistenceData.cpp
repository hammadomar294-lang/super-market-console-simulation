#include "classes/persistence/PersistenceData.h"

int PersistenceData::CategoryMaxId = 0;
int PersistenceData::ProductMaxId = 0;

const Category & PersistenceData::FindCategory(const unordered_map<int, Category> &map , int category_id)
{
    auto it = map.find(category_id);

    if (it == map.end())
        throw runtime_error("category wasn't found");

    return it->second;
}

pair<string, string> PersistenceData::LoadManagerData()
{
    ifstream file("data/manager.txt");

    if (!file.is_open())
        throw runtime_error("manager.txt couldn't be opened");

    pair<string, string> p;
    if (!(file >> p.first >> p.second))
    {
        throw runtime_error("manager.txt format invalid");
    }
    file.close();
    return p;
}

unordered_map<int , Product> PersistenceData::LoadProducts(const unordered_map<int , Category> & categories)
{   
    ifstream file("data/products.txt");
    if(!file.is_open())
        throw runtime_error("products.txt couldn't be opened");

    unordered_map<int , Product> products;

    int product_id , quantity , category_id;
    double price;
    string name;

    while(file>> product_id >> name >> price >> quantity >> category_id)
    {
        Product product{product_id,name,price,quantity,FindCategory(categories,category_id)};

        products[product_id] = product;

        if (product_id > ProductMaxId)
            ProductMaxId = product_id;
    }
    file.close();

    Product::SyncProductId(ProductMaxId);
    return products;
}

void PersistenceData::SaveProducts(const unordered_map<int , Product> & products)
{
    ofstream file("data/products.txt");
    if (!file.is_open())
        throw runtime_error("products.txt couldn't be opened");
    
    for (const auto & product : products)
    {
        file<<product.second.GetId() << " " << product.second.GetName() << " " << product.second.GetPrice() << " " <<
            product.second.GetQuantity() << " " << product.second.GetCategory().GetCategoryId() << "\n";
    }
    file.close();
}

unordered_map<int , Category> PersistenceData::LoadCategories()
{
    ifstream file("data/categories.txt");
    if(!file.is_open())
        throw runtime_error("categories.txt couldn't be opened");

    unordered_map<int , Category> categories;

    int id , tax , max_amount , least_amount;
    string name;

    while(file>>id>>name>>tax>>max_amount>>least_amount)
    {
        Category category{id,name,tax,max_amount,least_amount};

        categories[id] = category;
        
        if (id > CategoryMaxId)
            CategoryMaxId = id;
    }
    Category::SyncCategoryId(CategoryMaxId); // to make the system ready to make new categories
    file.close();
    return categories;
}

void PersistenceData::SaveCategories(const unordered_map<int , Category> &categories)
{
    ofstream file("data/categories.txt");
    if (!file.is_open())
        throw runtime_error("categories.txt couldn't be opened");
    
    for (const auto & category : categories)
    {
        file<<category.second.GetCategoryId()<< " " << category.second.GetCategoryName() << " " << category.second.GetTax() << " " <<
            category.second.GetMaxAmount() << " " << category.second.GetLeastAmount() << "\n";
    }
    file.close();
}

unordered_map<int , int> PersistenceData::LoadSales()
{
    ifstream file("data/sales.txt");
    if (!file.is_open())
        throw runtime_error("sales.txt couldn't be opened");

    int product_id , amount;
    unordered_map<int , int> sales;

    while (file>>product_id>>amount)
    {
        sales[product_id] = amount;
    }
    file.close();
    return sales;
}

void PersistenceData::SaveSales(const unordered_map<int , int> &sales)
{
    ofstream file("data/sales.txt");
    if (!file.is_open())
        throw runtime_error("sales.txt couldn't be opened");
    
    for(const auto & sale : sales)
    {
        file<< sale.first << " " << sale.second <<"\n";
    }
    file.close();
}
