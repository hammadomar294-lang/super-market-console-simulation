#include "classes/interface/Menus.h"


void Menus::ShowMainMenu()
{
    helper::ClearScreen();

    cout<<"\n \n";

    cout << "========================================\n";
    cout << "         Super Market System\n";
    cout << "========================================\n\n";

    cout << "1. Customer\n";
    cout << "2. Manager\n";
    cout << "3. Exit\n\n";

    helper::PrintLine();

    cout << "Choice: ";
}

// both manager and customer
void Menus::ShowProducts(const vector<Product>& products)
{
    helper::ClearScreen();

    cout << "\n\n";
    helper::PrintLine();

    for (int i = 0; i < products.size(); i += 2)
    {
        string first =
            to_string(i + 1) + ". " +
            products[i].GetName() + " " +
            to_string((int)products[i].GetSalesPrice()) + " EGP " +
            to_string(products[i].GetQuantity()) + " Unit";

        cout << left << setw(20) << first;

        if (i + 1 < products.size())
        {
            string second =
                to_string(i + 2) + ". " +
                products[i + 1].GetName() + " " +
                to_string((int)products[i + 1].GetSalesPrice()) + " EGP " +
                to_string(products[i + 1].GetQuantity()) + " Unit";

            cout << second;
        }

        cout << "\n\n";
    }

    helper::PrintLine();
    helper::GoBack();
}

vector<int> Menus::ShowProducts(const unordered_map<int, Product>& products)
{
    helper::ClearScreen();

    cout << "\n\n";

    helper::PrintLine();

    vector<int> displayed_ids;

    int count = 1;
    bool second_column = false;

    for (const auto& pair : products)
    {
        displayed_ids.push_back(pair.first);

        string text =
            to_string(count) + ". " +
            pair.second.GetName() + " " +
            to_string((int)pair.second.GetSalesPrice()) + " EGP " +
            to_string(pair.second.GetQuantity()) + " Unit";

        cout << left << setw(45) << text;

        if (second_column)
            cout << "\n\n";

        second_column = !second_column;

        count++;
    }

    if (!second_column)
        cout << "\n\n";

    helper::PrintLine();
    helper::GoBack();
    return displayed_ids;
}

// customer
void Menus::ShowCartItems(const Customer& customer)
{
    helper::ClearScreen();

    cout << "\n\n";
    cout << "Cart Items\n\n";

    const auto& items = customer.GetCart().GetItemsVector();

    if (items.empty())
    {
        cout << "Cart is empty\n\n";

        helper::PrintLine();

        return;
    }

    for (const auto& item : items)
    {
        const Product& product = item.GetProduct();

        cout << product.GetName()
             << " "
             << item.GetAmount()
             << "    ";
    }

    cout << "\n";

    helper::PrintLine();

    cout << "Total = "
         << customer.GetCart().GetTotalPrice()
         << " EGP\n\n";
}

void Menus::ShowCustomerHeader(const Customer& customer)
{
    cout << "========================================\n";
    cout << "            Customer Menu\n";
    cout << "========================================\n\n";

    cout << "Budget: "
         << customer.GetBudget()
         << " EGP\n\n";

    cout << "Cart:\n";
    ShowCartItems(customer);

    cout << "\n\n";

    cout << "Total = "
         << customer.GetCart().GetTotalPrice()
         << " EGP\n\n";

    helper::PrintLine();
}

void Menus::ShowCustomerOptions()
{
    cout << "1. Show Products\n";
    cout << "2. Products Ascending By Price\n";
    cout << "3. Products Descending By Price\n";
    cout << "4. Products By Category\n";
    cout << "5. Products Within Price Range\n";
    cout << "6. Undo\n";
    cout << "7. Redo\n";
    cout << "8. Clear Cart\n";
    cout << "9. Checkout\n";
    cout << "10. Exit\n";

    helper::PrintLine();

    cout << "Choice: ";
}

void Menus::ShowCustomerMenu(const Customer& customer)
{
    helper::ClearScreen();

    ShowCustomerHeader(customer);

    ShowCustomerOptions();
}

void Menus::ShowCustomerOptions()
{
    cout << "Choose product number: \n\n";
    cout << "0. Back\n";
    helper::PrintLine();
}

// manager
void Menus::ShowLowStockProducts(const vector<Product>& low_stock_products)
{
    helper::ClearScreen();

    if (low_stock_products.empty())
    {
        return;
    }

    cout << "\n\n";
    cout << "Low Stock Products\n";
    helper::PrintLine();
    cout<<"\n";

    for (int i = 0; i < low_stock_products.size(); i += 2)
    {
        string first =
            to_string(i + 1) + ". " +
            low_stock_products[i].GetName() +
            " | Qty: " +
            to_string(low_stock_products[i].GetQuantity());

        cout << left << setw(20) << first;

        if (i + 1 < low_stock_products.size())
        {
            string second =
                to_string(i + 2) + ". " +
                low_stock_products[i + 1].GetName() +
                " | Qty: " +
                to_string(low_stock_products[i + 1].GetQuantity());

            cout << second;
        }

        cout << "\n\n";
    }

    helper::PrintLine();
}

void Menus::ShowManagerOptions()
{
    helper::PrintLine();

    cout << "1. Products\n";
    cout << "2. Categories\n";
    cout << "3. Analytics\n";
    cout << "4. Exit\n\n";

    helper::PrintLine();
}

void Menus::ShowMangerMenu(const vector<Product> &low_stock_products)
{
    helper::ClearScreen();

    cout << "========================================\n";
    cout << "            Manager Menu\n";
    cout << "========================================\n\n";

    ShowLowStockProducts(low_stock_products);

    ShowManagerOptions();

    cout << "Choice: ";
}

void Menus::ShowManagerProductsOptionsMenu()
{
    helper::ClearScreen();

    cout << "========================================\n";
    cout << "            Products Menu\n";
    cout << "========================================\n\n";

    cout << "1. Show Products\n";
    cout << "2. Add Product\n";
    cout << "3. Remove Product\n";
    cout << "4. Rename Product\n";
    cout << "5. Change Product Price\n";
    cout << "6. Restock Product\n";
    cout << "7. Back\n";

    helper::PrintLine();

    cout << "Choice: ";
}

void Menus::ShowCategoriesMenu()
{
    helper::ClearScreen();

    cout << "========================================\n";
    cout << "           Categories Menu\n";
    cout << "========================================\n\n";

    cout << "1. Show Categories\n";
    cout << "2. Add Category\n";
    cout << "3. Rename Category\n";
    cout << "4. Restock Category\n";
    cout << "5. Back\n";

    helper::PrintLine();

    cout << "Choice: ";
}

void Menus::ShowAnalyticsMenu()
{
    helper::ClearScreen();

    cout << "========================================\n";
    cout << "            Analytics Menu\n";
    cout << "========================================\n\n";

    cout << "1. Most Sold Product\n";
    cout << "2. Least Sold Product\n";
    cout << "3. Ascending Sales\n";
    cout << "4. Descending Sales\n";
    cout << "5. Back\n";

    helper::PrintLine();

    cout << "Choice: ";
}

void Menus::ShowSales(const vector<pair<Product, int>> & sales)
{
    for (const auto & pair : sales)
    {
        cout<<pair.first.GetName()<< "  " <<pair.second<<"  Units"<<endl;
    }
}
