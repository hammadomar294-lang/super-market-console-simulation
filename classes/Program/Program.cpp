#include "classes/Program/Program.h"


void Program::Run()
{
    HandleMainMenu();
}

void Program::HandleMainMenu()
{
    int choice;
    while (true)
    {
        menus.ShowMainMenu();
        choice = helper::AskForInt("Enter you choice");
        switch (choice)
        {
            case 1:
            {
                HandleCustomerSession();
                break;
            }
            case 2:
            {
                HandleManagerSession();
                break;
            }
            case 3 :
                return;
            default:
            {
                cout<<"invalid choice try a number 1 to 3"<<endl;
                helper::Pause();
                break;
            }
        }
    }
}

void Program::HandleCustomerSession()
{
    double budget = helper::AskForDouble("Enter you budget");
    int choice;

    Customer customer{1,budget};

    try
    {
        while (true)
        {
            menus.ShowCustomerMenu(customer);
            choice = helper::AskForInt("Enter your choice: ");
            switch (choice)
            {
                case 1:
                {
                    HandleShowProducts(customer);
                    break;
                }
                case 2:
                {
                    HandleProductsAscending(customer);
                    break;
                }
                case 3:
                {
                    HandleProductsDescending(customer);
                    break;
                }
                case 4:
                {
                    HandleProductsByCategory(customer);
                    break;
                }
                case 5:
                {
                    HandleProductsWithinRange(customer);
                    break;
                }
                case 6:
                {
                    Undo(customer);
                    break;
                }
                case 7:
                {
                    Redo(customer);
                    break;
                }
                case 8:
                {
                    ClearCart(customer);
                    break;
                }
                case 9:
                {
                    CheckOut(customer);
                    break;
                }
                case 10:
                {
                    return;
                }
                default:
                {
                    cout<<"invalid choice try a number 1 to 10"<<endl;
                    helper::Pause();
                    break;
                }
            }
        }
    }
    catch(const exception& e)
    {
        cout << e.what() << '\n';
        helper::Pause();
    }
    
    
}

bool Program::Login()
{
    pair<string , string> manager_data =  PersistenceData::LoadManagerData();

    string name = helper::AskForString("Enter you name: ");
    if (name != manager_data.first)
        return false;
        
    string password = helper::AskForString("Enter you password");
    if (password != manager_data.second)
        return false;

    return true;
}

void Program::HandleProductsMenu()
{
    int choice;
        while (true)
        {
            menus.ShowManagerProductsOptionsMenu();
            choice = helper::AskForInt("Enter you choice: ");

            switch (choice)
            {
                // view products
                case 1:
                {
                    menus.ShowProducts(store.inventory.GetProductMap()); // it has pause inside
                    break;
                }
                // add product
                case 2:
                {
                    try
                    {
                        menus.ShowProducts(store.inventory.GetProductMap());

                        string name = helper::AskForString("Enter product name");
                        if (helper::DoesProductExist(name , store.inventory.GetProductMap()))
                        {
                            cout<<"Product allready exists"<<endl;
                            helper::Pause();
                            break;
                        }

                        string category_name = helper::AskForString("Enter category name name");
                        int category_id = helper::GetCategoryIdByName(category_name , store.inventory.GetCategoryMap());

                        double price = helper::AskForDouble("Enter product price");
                        int quantity = helper::AskForInt("Enter product quantity");
                        
                        Category & category = store.inventory.GetCategory(category_id);
                        Product product{name , price , quantity , category};

                        store.AddProduct(product);
                        cout<<"Product added successfully "<<endl;
                        helper::Pause();

                        break;
                    }
                    catch(const std::exception& e)
                    {
                        cout << e.what() << '\n';
                        helper::Pause();
                    }
                }
                // remove product
                case 3:
                {
                    try
                    {
                        menus.ShowProducts(store.inventory.GetProductMap());

                        string name = helper::AskForString("Enter product name");
                        if (!helper::DoesProductExist(name , store.inventory.GetProductMap()))
                        {
                            cout<<"Product doesn't exist"<<endl;
                            helper::Pause();
                            break;
                        }

                        int product_id = helper::GetProductIdByName(name);
                        store.inventory.RemoveProduct(product_id);

                        cout<<"product removed successfully"<<endl;
                        helper::Pause()
                        break;
                    }
                    catch(const std::exception& e)
                    {
                        cout << e.what() << '\n';
                        helper::Pause();
                    }
                }
                // rename product
                case 4:
                {
                    try
                    {
                        menus.ShowProducts(store.inventory.GetProductMap());

                        string name = helper::AskForString("Enter product name you wish to change");
                        if (!helper::DoesProductExist(name , store.inventory.GetProductMap()))
                        {
                            cout<<"Product doesn't exist"<<endl;
                            helper::Pause();
                            break;
                        }

                        string new_name = helper::AskForString("Enter new product name");
                        if (helper::DoesProductExist(new_name , store.inventory.GetProductMap()))
                        {
                            cout<<"Product name allready exist"<<endl;
                            helper::Pause();
                            break;
                        }

                        int product_id = helper::GetProductIdByName(name , store.inventory.GetProductMap());
                        store.inventory.RenameProduct(product_id , new_name);

                        cout<<"product renamed successfully to "<<endl;
                        helper::Pause();
                        break;
                    }
                    catch(const std::exception& e)
                    {
                        cout << e.what() << '\n';
                        helper::Pause();
                    }
                }
                // change price
                case 5:
                {
                    try
                    {
                        menus.ShowProducts(store.inventory.GetProductMap());

                        string name = helper::AskForString("Enter product name you wish to change it's price");
                        if (!helper::DoesProductExist(name , store.inventory.GetProductMap()))
                        {
                            cout<<"wrong name entered"<<endl;
                            helper::Pause();
                            break;
                        }
                        int product_id = helper::GetProductIdByName(name , store.inventory.GetProductMap());

                        double new_price = helper::AskForDouble("Enter new price");

                        store.inventory.ChangePrice(product_id , new_price);
                        cout<<"Price changed successfully"<<endl;
                        helper::Pause();

                        break;
                    }
                    catch(const std::exception& e)
                    {
                        cout << e.what() << '\n';
                        helper::Pause();
                    }
                }
                // restock product
                case 6:
                {
                    try
                    {
                        menus.ShowProducts(store.inventory.GetProductMap());

                        string name = helper::AskForString("Enter product name you wish to restock");
                        if (!helper::DoesProductExist(name , store.inventory.GetProductMap()))
                        {
                            cout<<"wrong name entered"<<endl;
                            helper::Pause();
                            break;
                        }
                        int product_id = helper::GetProductIdByName(name , store.inventory.GetProductMap());

                        int quantity = helper::AskForInt("Enter quantity");

                        store.inventory.RestockProduct(product_id , quantity);
                        cout<<"product restock successfully"<<endl;
                        helper::Pause();

                        break;
                    }
                    catch(const std::exception& e)
                    {
                        cout << e.what() << '\n';
                        helper::Pause();
                    }
                }
                case 7:
                {
                    return;
                }  
                default:
                {
                    cout<<"Invalid choice try 1 to 7"<<endl;
                    helper::Pause();
                    break;
                } 
            }
        }
    }

void Program::HandleCategoriesMenu()
{
    int choice;

    while (true)
    {
        menus.ShowCategoriesMenu();
        choice = helper::AskForInt("Enter your choice: ");

        switch (choice)
        {
            // show categories
            case 1:
            {
                menus.ShowCategories(store.inventory.GetCategoryMap());
                break;
            }
            // add category
            case 2:
            {
                try
                {
                    string name = helper::AskForString("Enter category name");

                    if (helper::DoesCategoryExist(name,store.inventory.GetCategoryMap()))
                    {
                        cout << "Category already exists"<< endl;
                        helper::Pause();
                        break;
                    }

                    int tax = helper::AskForInt("Enter category tax");

                    int max_amount = helper::AskForInt("Enter max amount");

                    int least_amount = helper::AskForInt("Enter least amount");

                    Category category{
                        name,
                        tax,
                        max_amount,
                        least_amount
                    };

                    store.AddCategory(category);
                    cout << "Category added successfully"<< endl;
                    helper::Pause();

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                    helper::Pause();
                    break;
                }
            }

            // rename category
            case 3:
            {
                try
                {
                    menus.ShowCategories(store.inventory.GetCategoryMap());

                    string name =helper::AskForString("Enter category name");

                    if (!helper::DoesCategoryExist(name,store.inventory.GetCategoryMap()))
                    {
                        cout << "Category not found"<< endl;
                        helper::Pause();
                        break;
                    }

                    string new_name = helper::AskForString("Enter new category name");

                    if (helper::DoesCategoryExist(new_name,store.inventory.GetCategoryMap()))
                    {
                        cout << "Category already exists"<< endl;
                        helper::Pause();
                        break;
                    }

                    int category_id = helper::GetCategoryIdByName(name,store.inventory.GetCategoryMap());

                    store.ReNameCategory(category_id,new_name);
                    cout << "Category renamed successfully"<< endl;
                    helper::Pause();

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                    helper::Pause();
                    break;
                }
            }

            // restock category
            case 4:
            {
                try
                {
                    menus.ShowCategories(store.inventory.GetCategoryMap());

                    string name = helper::AskForString("Enter category name");

                    if (!helper::DoesCategoryExist(name,store.inventory.GetCategoryMap()))
                    {
                        cout << "Category not found"<< endl;
                        helper::Pause();

                        break;
                    }

                    int category_id = helper::GetCategoryIdByName(name,store.inventory.GetCategoryMap());

                    store.ReStockCategory(category_id);
                    cout << "Category restocked successfully"<< endl;
                    helper::Pause();

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;
                    helper::Pause();
                    break;
                }
            }
            // back
            case 5:
            {
                return;
            }
            default:
            {
                cout << "Invalid choice try 1 to 5" << endl;
                helper::Pause();
                break;
            }
        }
    }
}

void Program::HandleAnalyticsMenu()
{
    int choice;

    while (true)
    {
        menus.ShowAnalyticsMenu();

        choice = helper::AskForInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
            {
                try
                {
                    const Product& product = store.MostSold();

                    cout << product.GetName() << " "
                         << product.GetSalesPrice() << " EGP "
                         << product.GetQuantity() << " Unit" << endl;

                    helper::Pause();

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;

                    helper::Pause();

                    break;
                }
            }

            case 2:
            {
                try
                {
                    const Product& product = store.LeastSold();

                    cout << product.GetName() << " "
                         << product.GetSalesPrice() << " EGP "
                         << product.GetQuantity() << " Unit" << endl;

                    helper::Pause();

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;

                    helper::Pause();

                    break;
                }
            }

            case 3:
            {
                try
                {
                    menus.ShowSales(store.AscendingSales());

                    helper::Pause();

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;

                    helper::Pause();

                    break;
                }
            }

            case 4:
            {
                try
                {
                    menus.ShowSales(store.DescendingSales());

                    helper::Pause();

                    break;
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;

                    helper::Pause();

                    break;
                }
            }

            case 5:
            {
                return;
            }

            default:
            {
                cout << "Invalid choice" << endl;

                helper::Pause();

                break;
            }
        }
    }
}

void Program::HandleManagerSession()
{
    if (!Login())
    {
        cout << "Invalid name or password\n";

        helper::Pause();

        return;
    }

    int choice;

    try
    {
        while (true)
        {
            menus.ShowMangerMenu(store.LowStockProducts());
            choice = helper::AskForInt("Enter you choice: ");

            switch (choice)
            {
                case 1:
                {
                    HandleProductsMenu();
                    break;
                }
                case 2:
                {
                    HandleCategoriesMenu();
                    break;
                }
                case 3:
                {
                    HandleAnalyticsMenu();
                    break;
                }
                case 4:
                {
                    return;
                }
                default:
                {
                    cout<<"Invalid choice try 1 to 4"<<endl;
                    helper::Pause();
                    break;
                } 
            }
        }
    }
    catch(const exception& e)
    {
        cout << e.what() << '\n';
        helper::Pause();
    }
}

void Program::HandleProducts(Customer& customer)
{
    menus.ShowProducts(store.inventory.GetProductMap());

    vector<int>& ids_vector =
        menus.GetDisplayedIds();

    cout << "0. Back" << endl << endl;

    int choice;

    while (true)
    {
        choice =
            helper::AskForInt(
                "Choose product number: ");

        if (choice == 0)
            return;

        if (choice > ids_vector.size())
        {
            cout << "Invalid choice" << endl;

            helper::Pause();

            continue;
        }

        try
        {
            int amount =
                helper::AskForInt(
                    "Enter amount");

            int product_id =
                ids_vector[choice - 1];

            store.AddToCart(
                customer,
                product_id,
                amount);

            cout << "Added successfully"
                 << endl;

            helper::Wait();
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;

            helper::Wait();
        }
    }
}

void Program::HandleProductsAscending(Customer& customer)
{
    vector<Product> products = store.GetProductsAscending();

    vector<int> ids_vector = menus.ShowProducts(products);

    cout << "0. Back" << endl << endl;

    int choice;

    while (true)
    {
        choice = helper::AskForInt("Choose product number: ");

        if (choice == 0)
            return;

        if (choice > ids_vector.size())
        {
            cout << "Invalid choice" << endl;

            helper::Pause();

            continue;
        }

        try
        {
            int amount = helper::AskForInt("Enter amount");

            int product_id = ids_vector[choice - 1];

            store.AddToCart(customer, product_id, amount);

            cout << "Added successfully" << endl;

            helper::Pause();
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;

            helper::Pause();
        }
    }
}

void Program::HandleProductsDescending(Customer& customer)
{
    vector<Product> products = store.GetProductsDescending();

    vector<int> ids_vector = menus.ShowProducts(products);

    cout << "0. Back" << endl << endl;

    int choice;

    while (true)
    {
        choice = helper::AskForInt("Choose product number: ");

        if (choice == 0)
            return;

        if (choice > ids_vector.size())
        {
            cout << "Invalid choice" << endl;

            helper::Pause();

            continue;
        }

        try
        {
            int amount = helper::AskForInt("Enter amount");

            int product_id = ids_vector[choice - 1];

            store.AddToCart(customer, product_id, amount);

            cout << "Added successfully" << endl;

            helper::Pause();
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;

            helper::Pause();
        }
    }
}

void Program::HandleProductsByCategory(Customer& customer)
{
    try
    {
        menus.ShowCategories(store.inventory.GetCategoryMap());

        string name = helper::AskForString("Enter category name");

        if (!helper::DoesCategoryExist(name, store.inventory.GetCategoryMap()))
        {
            cout << "Category not found" << endl;

            helper::Pause();

            return;
        }

        int category_id = helper::GetCategoryIdByName(name, store.inventory.GetCategoryMap());

        vector<Product> products = store.GetProductsByCategory(category_id);

        vector<int> ids_vector = menus.ShowProducts(products);

        cout << "0. Back" << endl << endl;

        int choice;

        while (true)
        {
            choice = helper::AskForInt("Choose product number: ");

            if (choice == 0)
                return;

            if (choice > ids_vector.size())
            {
                cout << "Invalid choice" << endl;

                helper::Pause();

                continue;
            }

            try
            {
                int amount = helper::AskForInt("Enter amount");

                int product_id = ids_vector[choice - 1];

                store.AddToCart(customer, product_id, amount);

                cout << "Added successfully" << endl;

                helper::Pause();
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;

                helper::Pause();
            }
        }
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;

        helper::Pause();
    }
}

void Program::HandleProductsWithinRange(Customer& customer)
{
    try
    {
        double low = helper::AskForDouble("Enter low price");

        double high = helper::AskForDouble("Enter high price");

        vector<Product> products = store.GetProductsWithinRange(low, high);

        vector<int> ids_vector = menus.ShowProducts(products);

        cout << "0. Back" << endl << endl;

        int choice;

        while (true)
        {
            choice = helper::AskForInt("Choose product number: ");

            if (choice == 0)
                return;

            if (choice > ids_vector.size())
            {
                cout << "Invalid choice" << endl;

                helper::Pause();

                continue;
            }

            try
            {
                int amount = helper::AskForInt("Enter amount");

                int product_id = ids_vector[choice - 1];

                store.AddToCart(customer, product_id, amount);

                cout << "Added successfully" << endl;

                helper::Pause();
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;

                helper::Pause();
            }
        }
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;

        helper::Pause();
    }
}

void Program::Undo(Customer& customer)
{
    try
    {
        store.Undo(customer);

        cout << "Undo successful" << endl;

        helper::Pause();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;

        helper::Pause();
    }
}

void Program::Redo(Customer& customer)
{
    try
    {
        store.Redo(customer);

        cout << "Redo successful" << endl;

        helper::Pause();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;

        helper::Pause();
    }
}

void Program::ClearCart(Customer& customer)
{
    store.ClearCart(customer);

    cout << "Cart cleared successfully" << endl;

    helper::Pause();
}

void Program::CheckOut(Customer& customer)
{
    try
    {
        store.CheckOut(customer);

        cout << "Checkout successful" << endl;

        helper::Pause();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;

        helper::Pause();
    }
}

