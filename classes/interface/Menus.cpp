#include "classes/interface/Menus.h"
#include "Menus.h"

void Menus::ShowProducts(const vector<Product> &products) 
{
    for (int i = 1 , j = 0; i <= products.size()/2 , j < products.size()/2 ; i++ , j++)
    {
            cout<<i + j<<". " <<products[i + j - 1].GetName() << " " << products[i + j - 1].GetPrice() << " EGP " << products[i + j - 1].GetQuantity() << "\t" <<
               i + j + 1<<". "<<products[i + j].GetName() << "  " << products[i + j].GetPrice() << " EGP " << products[i + j].GetQuantity() <<endl;
    }
    if (products.size() % 2 != 0)
        cout<<product.size()<< ". " <<products[products.size() - 1].GetName() << "  " << products[products.size() - 1].GetPrice() << " EGP  " << products[products.size() - 1].GetQuantity()<< " Unit" <<endl;
    
}

void Menus::ShowProducts(const unordered_map<int, Product> &products)
{
    
}
