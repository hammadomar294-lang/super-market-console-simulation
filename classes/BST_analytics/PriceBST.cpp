#include "PriceBST.h"



#pragma region helpers

void PriceBST::Insert(int id, int price)
{
    Node *temp = new Node{id,price};
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
        if (price >= current->Price)
            current = current->right;

        else 
            current = current->left;
    }
    
    if (price >= prev->Price)
        prev->right = temp;

    else 
        prev->left = temp;
    
}

void PriceBST::Clear(Node *current)
{
    //  base
    if (current == nullptr)
        return;

    Clear(current->left); // go far left until left -> null 
    Clear(current->right); // step after going far left which will go far right until right -> null
    delete current; // then delete node after those to steps which both resulted in return so they got completed
}

vector<int> PriceBST::DFS_inorder(Node *current) const
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

vector<int> PriceBST::DFS_reverse_inorder(Node *current) const
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
int PriceBST::GetMostExpensiveHelper(Node *current) const
{
    if (current == nullptr)
        throw runtime_error("subtree is empty");

    while (current->right != nullptr)
        current = current->right;

    return current->ProductId;
}

int PriceBST::GetCheapestHelper(Node *current) const
{
    if (current == nullptr)
        throw runtime_error("subtree is empty");

    while (current->left != nullptr)
            current = current->left;

    return current->ProductId;
}

vector<int> PriceBST::GetNthExpensiveHelper(Node *current, int n) const
{
    vector<int> result;

    if (current == nullptr || n <= 0)
        return result;

    auto right = GetNthExpensiveHelper(current->right, n);

    result.insert(result.end(), right.begin(), right.end());

    if (result.size() >= n)
        return result;

    
    result.push_back(current->ProductId);

    if (result.size() >= n)
        return result;

    auto left = GetNthExpensiveHelper(current->left, n - result.size());

    result.insert(result.end(), left.begin(), left.end());

    return result;
}
vector<int> PriceBST::GetNthCheapestHelper(Node *current, int n) const
{
    vector<int> result;

    if (current == nullptr || n <= 0)
        return result;

    auto left = GetNthCheapestHelper(current->left, n);

    result.insert(result.end(), left.begin(), left.end());

    if (result.size() >= n)
        return result;

    result.push_back(current->ProductId);

    if (result.size() >= n)
        return result;

    auto right = GetNthCheapestHelper(current->right, n - result.size());

    result.insert(result.end(), right.begin(), right.end());

    return result;
}

vector<int> PriceBST::GetIdsWithinRangeHelper(Node *current, double low, double high) const
{
    ;
}

bool PriceBST::IsEmpty() const
{
    return Root == nullptr;
}

#pragma endregion

#pragma region logic

void PriceBST::BuildTree(const unordered_map<int, Product> &prices)
{
    Clear(Root);
    Root = nullptr;
    for (const auto & pair : prices)
    {
        Insert(pair.first , pair.second.GetPrice());
    }
}

vector<int> PriceBST::GetAscendingIds() const
{
    return DFS_inorder(Root);
}

vector<int> PriceBST::GetDescendingIds() const
{
    return DFS_reverse_inorder(Root);
}

int PriceBST::GetMostExpensiveId() const
{
    return GetMostExpensiveHelper(Root);
}

int PriceBST::GetCheapestId() const
{
    return GetCheapestHelper(Root);
}

vector<int> PriceBST::GetNthExpensive(int n) const
{
    return GetNthExpensiveHelper(Root,n);
}

vector<int> PriceBST::GetNthCheapest(int n) const
{
    return GetNthCheapestHelper(Root , n);
}

#pragma endregion

PriceBST::~PriceBST()
{
    Clear(Root);
    Root = nullptr;
}

