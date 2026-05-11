#include "classes/Program/Program.h"
#include "Program.h"

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
                    cout<<"Invalid choice"<<endl;
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

