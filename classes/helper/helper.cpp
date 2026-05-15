#include "../helper/helper.h"

void helper::GoBack()
{
    cout<<"press any key to go back..."<<endl;
    cin.ignore();
    cin.get();
}

void helper::Pause()
{
    cout<<"press any key to continue..."<<endl;
    cin.ignore();
    cin.get();
}

void helper::ClearScreen()
{
    system("clear");
}
bool helper::Confirm()
{
    char answer;
    while (true)
    {
        cout<<"Are you sure ? (y/n) "<<endl;
        cin>>answer;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (answer == 'y' || answer == 'Y')
            return true;
        else if (answer == 'n' || answer == 'N')
            return false;
        
        cout<<"Invalid input try (y) for yes and (n) for no"<<endl;
    }
    
}

void helper::PrintLine()
{
    cout<<"-----------------------------------------"<<endl;
}
void helper::PrintBigLine()
{
    cout<<"------------------------------------------------------------------------"<<endl;
}

string helper::AskForString(string msg)
{
    string input;

    while (true)
    {
        cout << msg << endl;

        getline(cin >> ws, input);

        if (!input.empty())
            return input;

        cout << "Input cannot be empty. Try again.\n";
    }
}

int helper::AskForInt(string msg)
{
    int x;

    while (true)
    {
        cout << msg << endl;

        if (!(cin >> x))
        {
            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Invalid input. Try again.\n";

            continue;
        }

        if (x < 0)
        {
            cout << "Number cannot be negative.\n";

            continue;
        }

        return x;
    }
}
double helper::AskForDouble(string msg)
{
    double x;

    while (true)
    {
        cout << msg << endl;

        if (!(cin >> x))
        {
            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Invalid input. Try again.\n";

            continue;
        }

        if (x <= 0.0)
        {
            cout << "Number must be greater than 0.\n";

            continue;
        }

        return x;
    }
}

int helper::GetProductIdByName(const string &name, const unordered_map<int, Product> &products)
{
    for (const auto & pair : products)
    {
        if(pair.second.GetName() == name)
            return pair.first;
    }
    throw runtime_error("product was not found try again");
}
bool helper::DoesProductExist(const string &name, const unordered_map<int, Product> &products)
{
    for (const auto & pair : products)
    {
        if(pair.second.GetName() == name)
            return true;
    }
    return false;
}
int helper::GetCategoryIdByName(const string &name, const unordered_map<int, Category> &categories)
{
    for (const auto & pair : categories)
    {
        if (pair.second.GetCategoryName() == name)
            return pair.first;
    }
    throw runtime_error("category was not found try again");
}

bool helper::DoesCategoryExist(const string &name, const unordered_map<int, Category> &categories)
{
    for (const auto & pair : categories)
    {
        if(pair.second.GetCategoryName() == name)
            return true;
    }
    return false;
}
