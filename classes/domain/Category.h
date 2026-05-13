#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
using namespace std;
class Category
{
private:
    int CategoryId;
    string CategoryName;
    int Tax;
    int MaxAmount;
    int LeastAmount;

    static int NextId;

    static int ValidateId(int id);
    static string ValidateName(const string& name);
    static int ValidateTax(int tax);
    static int ValidateMaxAmount(int maxAmount);
    static int ValidateLeastAmount(int leastAmount, int maxAmount);


public:
    int GetCategoryId() const;

    const string& GetCategoryName() const;
    void SetCategoryName(const string& name);

    int GetTax() const;
    void SetTax(int tax);

    int GetMaxAmount() const;
    void SetMaxAmount(int max_amount);

    int GetLeastAmount() const;
    void SetLeastAmount(int least_amount);

    static void SyncCategoryId(int max_id);
    
    // use NextCategoryId to make a new Category
    Category(const string& name,int tax,int maxAmount,int leastAmount);

    // for an existing Category inside the system does not use NextCategoryId
    Category(int id,const string& name,int tax,int maxAmount,int leastAmount);
    
};

#endif