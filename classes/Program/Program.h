#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>


#include "../store/Store.h"
#include "../interface/Menus.h"
#include "../domain/user/Manager.h"
#include "../domain/user/customer.h"
#include "../persistence/PersistenceData.h"

class Program
{
private:
    Store store;
    Menus menus;

public:
    void Run();

private:

    void HandleMainMenu();
    // main sessions
    void HandleCustomerSession();
    void HandleManagerSession();
    void StartCustomerSession();
    void EndCustomerSession();
    
    
    // manager 
    bool Login();
    void HandleProductsMenu();
    void HandleCategoriesMenu();
    void HandleAnalyticsMenu();
    void StartManagerSession();
    void EndManagerSession();

    // customer 
    void HandleProducts(Customer& customer); // all shows the product in inventory but take customer for it's cart
    void HandleProductsAscending(Customer& customer);
    void HandleProductsDescending(Customer& customer);
    void HandleProductsByCategory(Customer& customer);
    void HandleProductsWithinRange(Customer& customer);
    void Undo(Customer& customer);
    void Redo(Customer& customer);
    void ClearCart(Customer& customer);
    void CheckOut(Customer& customer);
};

#endif