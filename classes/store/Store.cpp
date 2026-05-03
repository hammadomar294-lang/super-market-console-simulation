#include "classes/store/Store.h"
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

Order Store::CheckOut(Customer &customer)
{
    auto & items_vector = customer.GetCart().GetItemsVector();
    if (items_vector.empty())
        throw runtime_error("cart is empty");

    Order order{items_vector};

    customer.GetCart().Clear();

    return order;
}

vector<Product> Store::GetProductsAscending() const
{
    auto & prices_Ids = analyzer.GetAscending_Price_Ids();   
    vector <Product> products;
    for (const auto & id : prices_Ids)
    {
        products.push_back(inventory.GetProduct(id));
    }
    return products;
}

vector<Product> Store::GetProductsDescending() const
{
    auto & prices_Ids = analyzer.GetDescending_Price_Ids();   
    vector <Product> products;
    for (const auto & id : prices_Ids)
    {
        products.push_back(inventory.GetProduct(id));
    }
    return products;
}

vector<Product> Store::GetProductsByCategory(int category_id)
{
    auto & products_map = inventory.GetProductMap();
    vector <Product> products;
    for (const auto & pair : products_map)
    {
        if (pair.second.GetCategory().GetCategoryId() == category_id)
            products.push_back(pair.second);
    }
    return products;
}

vector<Product> Store::GetProductsWithinRange(double low, double high)
{
    auto & prices_Ids = analyzer.GetPrice_IdsWithinRange(low , high);
    vector <Product> products;
    for (const auto & id : prices_Ids)
    {
        products.push_back(inventory.GetProduct(id));
    }
    return products;
}

const Product & Store::GetMostExpensive() const
{
    int id = analyzer.GetMostExpensiveId();
    return inventory.GetProduct(id);
}

const Product & Store::GetCheapest() const
{
    int id =  analyzer.GetCheapestId();
    return inventory.GetProduct(id);
}

const vector<CartItem> &Store::ShowCartItems(const Customer &customer) const
{
    customer.GetCart().GetItemsVector();
}

void Store::ClearCart(Customer &customer)
{
    customer.GetCart().Clear();
}

void Store::AddProduct(const Product &product)
{
    inventory.AddProduct(product);
}

void Store::ReMoveProduct(int product_id)
{
    inventory.RemoveProduct(product_id);
}

void Store::ReNameProduct(int product_id, const string &new_name)
{
    inventory.RenameProduct(product_id , new_name);
}

void Store::ReStockProduct(int product_id, int amount)
{
    inventory.RestockProduct(product_id , amount);
}

void Store::ChangeProductPrice(int product_id, double new_price)
{
    inventory.ChangePrice(product_id , new_price);
}

vector<Product> Store::LowStockProducts() const
{
    return inventory.GetLowStockProducts();
}

void Store::AddCategory(const Category &category)
{
    inventory.AddCategory(category);
}

void Store::ReNameCategory(int category_id, const string &new_name)
{
    inventory.RenameCategory(category_id , new_name);
}

void Store::ReStockCategory(int category_id)
{
    inventory.RestockCategory(category_id);
}

Product Store::MostSold() const
{
    int id = analyzer.GetMostSoldId();
    return inventory.GetProduct(id);
}

const Product &Store::LeastSold() const
{
    int id = analyzer.GetLeastSoldId();
    return inventory.GetProduct(id);
}

 vector<Product> Store::AscendingSales() const
{
    vector <int> ids = analyzer.GetAscending_Sales_Ids();
    vector < pair<Product , int> >  sales;
    pair<Product , int> temp;
    for (const auto & id : ids)
    {   
        temp.first = inventory.GetProduct(id);
        temp.second = inventory.GetSalesMap().find(id);
        sales.push_back(temp);
    } 
    return sales;
}

 vector<pair<Product, int>> Store::DescendingSales() const
{
    vector <int> ids = analyzer.GetDescending_Sales_Ids();
    vector < pair<Product , int> >  sales;
    pair<Product , int> temp;
    for (const auto & id : ids)
    {   
        temp.first = inventory.GetProduct(id);
        temp.second = inventory.GetSalesMap().find(id);
        sales.push_back(temp);
    } 
    return sales;
}

bool Store::CanAffordCart(const Customer &customer) const
{
    return customer.GetCart().GetTotalPrice() <= customer.GetBudget();
}

bool Store::IsCartEmpty(const Customer &customer) const
{
    return customer.GetCart().Empty();
}

void Store::EnqueueOrder(Order & order)
{
    OrderQueue.push(order);
}

void Store::DequeueOrder()
{
    OrderQueue.pop();
}

pair<double, int> Store::CalculateTotalAndNumberOfItems(const Customer &customer) const
{
    pair<double, int> total_and_numberOfItems;

    total_and_numberOfItems.first = customer.GetCart().GetTotalPrice();
    total_and_numberOfItems.second = customer.GetCart().GetItemsVector().size();

    return total_and_numberOfItems;
}

void Store::EndSession()
{
}
