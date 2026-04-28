#ifndef ANALYZER_H
#define ANALYZER_H

#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include "classes/BST_analytics/PriceBST.h"
#include "classes/BST_analytics/SalesBST.h"
using namespace std;



class Analyzer
{
private:
    SalesBST SalesTree;
    PriceBST PricesTree;
public:

    // sales functions
    void BuildSalesTree(const unordered_map <int , int> & sales_map);
    void BuildPricesTree(const unordered_map <int , int> & prices_map);
    
    vector <int> GetAscending_Sales_Ids() const;
    vector <int> GetDescending_Sales_Ids() const;
    vector <int> GetNthMostSoldIds(int n) const;

    int GetMostSoldId() const;
    int GetLeastSoldId() const;

    // price functions
    vector <int> GetAscending_Price_Ids() const;
    vector <int> GetDescending_Price_Ids() const;

    int GetMostExpensiveId() const;
    int GetCheapestId() const;

    vector <int> GetNthExpensive(int n) const;
    vector <int> GetNthCheapest(int n) const;

    ~Analyzer() = default;

};

#endif