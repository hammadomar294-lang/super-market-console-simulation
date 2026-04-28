#ifndef SALESBST_H
#define SALESBST_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdexcept>
using namespace std;



class SalesBST
{
private:
    struct Node
    {
        int ProductId;
        int Amount;

        Node * right;
        Node * left;

        static int ValidateId(int id)
        {
            if (id <= 0)
                throw runtime_error("can't enter value < 0");
            return id;
        }
        static int ValidateAmount(int amount)
        {
            if (amount <= 0)
                throw runtime_error("can't enter value < 0");
            return amount;
        }

        Node(int product_id, int amount) : ProductId(ValidateId(product_id)), Amount(ValidateAmount(amount)) 
                                                                            , right(nullptr) , left(nullptr)
        {}

    };

    Node * Root;

    void Insert(int id , int amount);
    void Clear(Node * current);

    vector <int> DFS_inorder(Node * current) const;
    vector <int> DFS_reverse_inorder(Node * current) const;
    vector <int> NthMostSoldHelper(Node * current , int n) const;
    int GetMostSoldIdHelper(Node * current) const;
    int GetLeastSoldIdHelper(Node * current) const;

public:

    void BuildTree(const unordered_map<int , int> & sales_map);

    vector <int> GetAscendingIds() const;
    vector <int> GetDescendingIds() const;
    vector <int> GetNthMostSoldIds(int n) const;

    int GetMostSoldId() const;
    int GetLeastSoldId() const;
    
    bool IsEmpty() const;

    ~SalesBST();
    SalesBST();
};

#endif