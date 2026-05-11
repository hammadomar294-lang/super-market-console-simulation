#include "classes/helper/helper.h"
#include "helper.h"


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
    cout << msg << endl;

    int x;

    while(!(cin >> x))
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid input. Try again:\n";
    }

    return x;
}

double helper::AskForDouble(string msg)
{
    cout<<msg<<endl;

    double x;
    while (!(cin>>x))
    {
        cin.clear();
        cin.ignore(1000 , '\n');
        cout << "Invalid input. Try again:\n";
    }
    return x;
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
int helper::GetCategoryIdByName(const string &name, const unordered_map<int, Category> &categories)
{
    for (const auto & pair : categories)
    {
        if (pair.second.GetCategoryName() == name)
            return pair.first;
    }
    throw runtime_error("category was not found try again");
}