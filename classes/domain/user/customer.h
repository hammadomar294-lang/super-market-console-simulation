#ifndef CUSTOMER_H
#define CUSTOMER_H


#include <string>
#include "classes/store/Cart.h"
#include "classes/domain/user/User.h"
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
    Cart & GetCart() const;
};

#endif 