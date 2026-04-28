#include "classes/BST_analytics/SalesBST.h"



#pragma region helpers

vector<int> SalesBST::DFS_inorder(Node* current) const
{
    vector<int> result;

    if (current == nullptr)
        return result;

    auto left = DFS_inorder(current->left);
    result.insert(result.end(), left.begin(), left.end());

    result.push_back(current->ProductId);

    auto right = DFS_inorder(current->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}
vector<int> SalesBST::DFS_reverse_inorder(Node* current) const
{
    vector<int> result;

    if (current == nullptr)
        return result;

    auto right = DFS_reverse_inorder(current->right);
    result.insert(result.end(), right.begin(), right.end());

    result.push_back(current->ProductId);

    auto left = DFS_reverse_inorder(current->left);
    result.insert(result.end(), left.begin(), left.end());

    return result;
}

vector<int> SalesBST::NthMostSoldHelper(Node* current, int n) const
{
    vector<int> result;

    if (current == nullptr || n <= 0)
        return result;

    // go right first (higher sales first)
    auto right = NthMostSoldHelper(current->right, n);

    result.insert(result.end(), right.begin(), right.end());

    if (result.size() >= n)
        return result;

    // add root
    result.push_back(current->ProductId);

    if (result.size() >= n)
        return result;

    // go left
    auto left = NthMostSoldHelper(current->left, n - result.size());

    result.insert(result.end(), left.begin(), left.end());

    return result;
}

int SalesBST::GetMostSoldIdHelper(Node * current) const
{
    if (current == nullptr)
            throw runtime_error("subtree is empty");

        while (current->right != nullptr)
            current = current->right;

        return current->ProductId;
}

int SalesBST::GetLeastSoldIdHelper(Node *current) const
{
    if (current == nullptr)
            throw runtime_error("subtree is empty");

        while (current->left != nullptr)
            current = current->left;

        return current->ProductId;
}

bool SalesBST::IsEmpty() const
{
    return Root == nullptr;
}

void SalesBST::Insert(int id, int amount)
{
    Node *temp = new Node{id,amount};
    if (IsEmpty())
    { 
        Root = temp;
        return;
    }
    Node * current = Root;
    Node * prev = Root;
    while (current != nullptr)
    {
        prev = current;
        if (amount > current->Amount)
            current = current->right;

        else 
            current = current->left;
    }
    
    if (amount > prev->Amount)
        prev->right = temp;

    else 
        prev->left = temp;
    
}

void SalesBST::Clear(Node *current) // with recursion
{
    //  base
    if (current == nullptr)
        return;

    Clear(current->left); // go far left until left -> null 
    Clear(current->right); // step after going far left which will go far right until right -> null
    delete current; // then delete node after those to steps which both resulted in return so they got completed
}

#pragma endregion

#pragma region logic

void SalesBST::BuildTree(const unordered_map<int, int> &sales_tree)
{
    for (const auto & pair : sales)
    {
        Insert(pair.first , pair.second);
    }
}

vector<int> SalesBST::GetAscendingIds() const
{
    return DFS_inorder(Root);
}

vector<int> SalesBST::GetDescendingIds() const
{
    return DFS_reverse_inorder(Root);
}

vector<int> SalesBST::GetNthMostSoldIds(int n) const
{
    return NthMostSoldHelper(Root , n);
}

int SalesBST::GetMostSoldId() const
{
    return GetMostSoldIdHelper(Root);
}

int SalesBST::GetLeastSoldId() const
{
    return GetLeastSoldIdHelper(Root);
}

#pragma endregion

SalesBST::~SalesBST()
{
    Clear(Root);
}

SalesBST::SalesBST() : Root(nullptr)
{}
