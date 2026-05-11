#include "classes/domain/Category.h"

int Category::NextId = 1;

#pragma region helpers 

int Category::ValidateId(int id)
{
    if (id <= 0)
        throw invalid_argument("invalid category id");

    return id;
}

string Category::ValidateName(const string& name)
{
    if (name.empty())
        throw invalid_argument("category name cannot be empty");

    return name;
}

int Category::ValidateTax(int tax)
{
    if (tax < 0 || tax > 100)
        throw invalid_argument("invalid tax value");

    return tax;
}

int Category::ValidateMaxAmount(int maxAmount)
{
    if (maxAmount <= 0)
        throw invalid_argument("invalid max amount");

    return maxAmount;
}

int Category::ValidateLeastAmount(int leastAmount, int maxAmount)
{
    if (leastAmount < 0 || leastAmount >= maxAmount)
        throw invalid_argument("invalid least amount");

    return leastAmount;
}
#pragma endregion

#pragma region getters setters

int Category::GetCategoryId() const
{
    return CategoryId;
}

const string& Category::GetCategoryName() const
{
    return CategoryName;
}

void Category::SetCategoryName(const string& name)
{
    if (name.empty())
        throw invalid_argument("category name cannot be empty");

    CategoryName = name;
}

int Category::GetTax() const
{
    return Tax;
}

void Category::SetTax(int tax)
{
    if (tax < 0 || tax > 100)
        throw invalid_argument("invalid tax value");

    Tax = tax;
}

int Category::GetMaxAmount() const
{
    return MaxAmount;
}

void Category::SetMaxAmount(int maxAmount)
{
    if (maxAmount <= 0)
        throw invalid_argument("invalid max amount");

    if (maxAmount <= LeastAmount)
        throw invalid_argument("max must be greater than least");

    MaxAmount = maxAmount;
}

int Category::GetLeastAmount() const
{
    return LeastAmount;
}

void Category::SetLeastAmount(int leastAmount)
{
    if (leastAmount < 0)
        throw invalid_argument("invalid least amount");

    if (leastAmount >= MaxAmount)
        throw invalid_argument("least must be smaller than max");

    LeastAmount = leastAmount;
}
void Category::SyncCategoryId(int max_id)
{
    if (max_id < 0) return;
    
    if(NextId <= max_id)
        NextId = max_id + 1;
}
#pragma endregion

Category::Category(const string &name, int tax, int maxAmount, int leastAmount) : CategoryId(NextId++) , CategoryName(ValidateName(name)), Tax(ValidateTax(tax)),
MaxAmount(ValidateMaxAmount(maxAmount)), LeastAmount(ValidateLeastAmount(leastAmount, maxAmount))
{}

Category::Category(int id, const string &name, int tax, int maxAmount, int leastAmount) : CategoryId(ValidateId(id)), 
CategoryName(ValidateName(name)), Tax(ValidateTax(tax)),
MaxAmount(ValidateMaxAmount(maxAmount)), LeastAmount(ValidateLeastAmount(leastAmount, maxAmount))
{}


