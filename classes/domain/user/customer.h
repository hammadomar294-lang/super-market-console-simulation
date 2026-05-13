#ifndef CUSTOMER_H
#define CUSTOMER_H


#include <string>
#include "../../store/Cart.h"
#include "User.h"
#include <stdexcept>
using namespace std;


class Customer : public User
{
private :
    Cart cart;
    double Budget;
    static double ValidateBudget(double budget);
public :
    Customer(int id , double budget);

    double GetBudget() const;
    void DeductFromBudget(double cart_total) ;
    Cart & GetCart();
    const Cart& GetCart() const;
};

#endif 