#ifndef PRICEBST_H
#define PRICEBST_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <utility>
#include "../domain/Product.h"
using namespace std;



class PriceBST
{
private:
    struct Node
    {
        int ProductId;
        double Price;

        Node * right;
        Node * left;

        static int ValidateId(int id)
        {
            if (id <= 0)
                throw runtime_error("can't enter value <= 0");
            return id;
        }
        static double ValidatePrice(double price)
        {
            if (price <= 0.0)
                throw runtime_error("can't enter value <= 0");
            return price;
        }

        Node(int id , double price) : ProductId(ValidateId(id)) , 
                                      Price(ValidatePrice(price)) , right(nullptr) , left(nullptr)
        {}
    };

    Node * Root = nullptr;

    void Insert(int id , double price);
    void Clear(Node * current);

    vector <int> DFS_inorder(Node * current) const;
    vector <int> DFS_reverse_inorder(Node * current) const;

    int GetMostExpensiveHelper(Node * current) const;
    int GetCheapestHelper(Node * current) const;

    vector <int> GetNthExpensiveHelper(Node * current , int n) const;
    vector <int> GetNthCheapestHelper(Node * current , int n) const;
    void GetIdsWithinRangeHelper(Node *current, double low, double high , vector<int> & ids) const;
    
public:

    void BuildTree(const unordered_map<int , Product> & prices);

    vector <int> GetAscendingIds() const;
    vector <int> GetDescendingIds() const;
    vector <int> GetIdsWithinRange(double low , double high) const;
    int GetMostExpensiveId() const;
    int GetCheapestId() const;
    
    vector <int> GetNthExpensive(int n) const;
    vector <int> GetNthCheapest(int n) const;

    bool IsEmpty() const;

    ~PriceBST();
};

#endif