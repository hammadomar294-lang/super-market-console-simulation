#include "classes/BST_analytics/Analyzer.h"

void Analyzer::BuildSalesTree(const unordered_map<int, int> &sales_map)
{
    SalesTree.BuildTree(sales_map);
}

void Analyzer::BuildPricesTree(const unordered_map<int, Product> &prices_map) 
{
    PricesTree.BuildTree(prices_map);
}

Analyzer::Analyzer(const unordered_map<int, int> &sales_map, const unordered_map<int, Product> &prices_map)
{
    BuildPricesTree(prices_map);
    BuildSalesTree(sales_map);
}

vector<int> Analyzer::GetAscending_Sales_Ids() const
{
    return SalesTree.GetAscendingIds();
}

vector<int> Analyzer::GetDescending_Sales_Ids() const
{
    return SalesTree.GetDescendingIds();
}

vector<int> Analyzer::GetNthMostSoldIds(int n) const
{
    return SalesTree.GetNthMostSoldIds(n);
}

int Analyzer::GetMostSoldId() const
{
    return SalesTree.GetMostSoldId();
}

int Analyzer::GetLeastSoldId() const
{
    return SalesTree.GetLeastSoldId();
}

vector<int> Analyzer::GetAscending_Price_Ids() const
{
    return PricesTree.GetAscendingIds();
}

vector<int> Analyzer::GetDescending_Price_Ids() const
{
    return PricesTree.GetDescendingIds();
}

vector<int> Analyzer::GetPrice_IdsWithinRange(double low, double high) const
{
    return vector<int>();
}

int Analyzer::GetMostExpensiveId() const
{
    return PricesTree.GetMostExpensiveId();
}

int Analyzer::GetCheapestId() const
{
    return PricesTree.GetCheapestId();
}

vector<int> Analyzer::GetNthExpensive(int n) const
{
    return PricesTree.GetNthExpensive(n);
}

vector<int> Analyzer::GetNthCheapest(int n) const
{
    return PricesTree.GetNthCheapest(n);
}
