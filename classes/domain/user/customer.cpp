#include "classes/domain/user/customer.h"

double Customer::ValidateBudget(double budget)
{
    if (budget <= 0)
        throw invalid_argument("can't enter a value <= 0");
    return budget;
}

Customer::Customer(int id, double budget) : User(id), Budget(ValidateBudget(budget))
{}

double Customer::GetBudget() const
{
    return Budget;
}

Cart &Customer::GetCart() const
{
    return cart;
}
